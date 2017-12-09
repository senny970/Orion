#pragma once

namespace H
{ 
  LRESULT __stdcall WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

  HRESULT __stdcall D3D_EndScene(IDirect3DDevice9* thisptr);

  HRESULT __stdcall D3D_Reset(
    IDirect3DDevice9* thisptr,
    D3DPRESENT_PARAMETERS* pPresentationParameters);

  bool __stdcall IClientMode_CreateMove(
    float flInputSampleTime, SDK::CUserCmd* pCmd);
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(
  HWND hwnd,
  UINT uMsg,
  WPARAM wParam,
  LPARAM lParam);
