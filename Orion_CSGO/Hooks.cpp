#include "OrionIncludes.h"

LRESULT CALLBACK H::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
    ImGui::Begin(XS("Simple box")/*, 0, ImGuiWindowFlags_AlwaysAutoResize */);
    if (ImGui::Button(XS("Press me")))
    {
      Beep(600, 30);
    }
    ImGui::Text(XS("Application average %.3f ms/frame (%.1f FPS)"), 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
  }

  ImGui::Render();
  return U::VMTHookMgr::GetHook(XS("D3D_EndScene"))->GetOriginFn<IDirect3DDevice9_EndSceneFn>()(thisptr);
}

HRESULT __stdcall H::D3D_Reset(
  IDirect3DDevice9* thisptr,
  D3DPRESENT_PARAMETERS* pPresentationParameters)
{
  cout << "D3D_Reset called!" << endl;


  return U::VMTHookMgr::GetHook(XS("D3D_Reset"))->GetOriginFn<IDirect3DDevice9_ResetFn>()(thisptr, pPresentationParameters);
}