#include "OrionIncludes.h"

LRESULT __stdcall H::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  if (GetAsyncKeyState(ORION_MENU_BTN))
  {
    G::bIsMenuShown = !G::bIsMenuShown;
    ImGui::GetIO().MouseDrawCursor = G::bIsMenuShown;
    
    string sConsoleCMD = XS("cl_mouseenable ") + to_string(!G::bIsMenuShown);
    G::pEngine->ClientCmd_Unrestricted2(sConsoleCMD.c_str());

    Beep(700, 200);
  }

  if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam))
  {
    if (G::bIsMenuShown)
    {
      return true;
    }
  }

  return CallWindowProc(G::oWndProc, hwnd, uMsg, wParam, lParam);
}

HRESULT __stdcall H::D3D_EndScene(IDirect3DDevice9* thisptr)
{
  ImGui_ImplDX9_NewFrame();

  if (G::bIsMenuShown)
  {
    ImGui::Begin(XS("Orion Hooks Menu"));

    C_BunnyHop* pBhop = (C_BunnyHop*)C_CheatMgr::GetCheat(XS("C_BunnyHop"));
    if (pBhop)
    {
      ImGui::Checkbox(XS("Enable bunnyhop"), &pBhop->m_bEnabled);
      if (pBhop->m_bEnabled)
      {
        ImGui::Checkbox(XS("Autostrafe"), &pBhop->m_bAutoStrafe);
      }
    }
    ImGui::Text(XS("Application average %.3f ms/frame (%.1f FPS)"),
      1000.0f / ImGui::GetIO().Framerate,
      ImGui::GetIO().Framerate);
    ImGui::End();
  }

  ImGui::Render();
  return U::VMTHookMgr::GetHook(XS("D3D_EndScene"))->
    GetOriginFn<IDirect3DDevice9_EndSceneFn>()(thisptr);
}

HRESULT __stdcall H::D3D_Reset(
  IDirect3DDevice9* thisptr,
  D3DPRESENT_PARAMETERS* pPresentationParameters)
{
  ImGui_ImplDX9_InvalidateDeviceObjects();

  HRESULT hRes = U::VMTHookMgr::GetHook(XS("D3D_Reset"))->
    GetOriginFn<IDirect3DDevice9_ResetFn>()(thisptr, pPresentationParameters);

  ImGui_ImplDX9_CreateDeviceObjects();

  return hRes;
}

bool __stdcall H::IClientMode_CreateMove(float flInputSampleTime, SDK::CUserCmd* pCmd)
{
  C_BunnyHop* pBhop = (C_BunnyHop*)C_CheatMgr::GetCheat(XS("C_BunnyHop"));
  if (pBhop)
  {
    pBhop->Perform(pCmd);
  }

  return U::VMTHookMgr::GetHook(XS("IClientMode_CreateMove"))->
    GetOriginFn<IClientMode_CreateMoveFn>()(flInputSampleTime, pCmd);
}