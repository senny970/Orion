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
  if (!G::pEngine->IsTakingScreenshot() && G::pEngine->IsActiveApp())
  {
    ImGui_ImplDX9_NewFrame();
    
    if (G::bIsMenuShown)
    {
      if (ImGui::Begin(XS("Orion Hooks Menu"), 0,
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
      {
        GET_CHEAT(C_Bhop, pBhop);
        if (pBhop)
        {
          pBhop->OnDraw();
        }
        GET_CHEAT(C_FakeLag, pFakeLag);
        if (pFakeLag)
        {
          pFakeLag->OnDraw();
        }
        GET_CHEAT(C_Radar, pRadar);
        if (pRadar)
        {
          pRadar->OnDraw();
        }
        ImGui::End();
      }
    }

    ImGui::Render();
  }

  return U::VMTHookMgr::GetHook(XS("D3D_EndScene"))->
    GetOriginFn<IDirect3DDevice9_EndSceneFn>()(thisptr);
}

HRESULT __stdcall H::D3D_Reset(
  IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
  ImGui_ImplDX9_InvalidateDeviceObjects();

  HRESULT hRes = U::VMTHookMgr::GetHook(XS("D3D_Reset"))->
    GetOriginFn<IDirect3DDevice9_ResetFn>()(thisptr, pPresentationParameters);

  ImGui_ImplDX9_CreateDeviceObjects();
  return hRes;
}

bool __stdcall H::IClientMode_CreateMove(
  float flInputSampleTime, SDK::CUserCmd* pCmd)
{
  GET_CHEAT(C_Bhop, pBhop);
  if (pBhop)
  {
    pBhop->OnCreateMove(pCmd);
  }
  GET_CHEAT(C_FakeLag, pFakeLag);
  if (pFakeLag)
  {
    pFakeLag->OnCreateMove(pCmd);
  }
  GET_CHEAT(C_Radar, pRadar);
  if (pRadar)
  {
    pRadar->OnCreateMove(pCmd);
  }

  return U::VMTHookMgr::GetHook(XS("IClientMode_CreateMove"))->
    GetOriginFn<IClientMode_CreateMoveFn>()(flInputSampleTime, pCmd);
}

void __stdcall H::IBaseClientDll_CreateMove(
  int sequence_number, float input_sample_frametime, bool active)
{

  return U::VMTHookMgr::GetHook(XS("IBaseClientDll_CreateMove"))->
    GetOriginFn<IBaseClientDll_CreateMoveFn>()(
      sequence_number, input_sample_frametime, active);
}

void __declspec(naked) H::CHLClient_CreateMove()
{
  __asm
  {
    mov bl, G::bSendPacket;
    ret;
  }
}