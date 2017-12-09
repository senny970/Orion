#pragma once

GVAR(HINSTANCE, hDllInstance, NULL)
GVAR(HWND, hCurentWindow, NULL)
GVAR(IDirect3DDevice9*, pD3D, NULL)
GVAR(WNDPROC, oWndProc, NULL)
GVAR(SDK::IVEngineClient*, pEngine, NULL)
GVAR(SDK::IBaseClientDLL*, pClient, NULL)
GVAR(SDK::IClientEntityList*, pEntityList, NULL)
GVAR(SDK::CGlobalVarsBase*, pGlobals, NULL)
GVAR(SDK::CInput*, pInput, NULL)
GVAR(SDK::IEngineTrace*, pEngineTrace, NULL)
GVAR(SDK::IClientMode*, pClientMode, NULL)
GVAR(SDK::IVModelInfoClient*, pModelInfo, NULL)
GVAR(SDK::IEngineSound*, pSound, NULL)
GVAR(SDK::IVModelRender*, pModelRender, NULL)
GVAR(SDK::IVRenderView*, pRenderView, NULL)
GVAR(SDK::IMaterialSystem*, pMaterialSystem, NULL)
GVAR(SDK::ISurface*, pSurface, NULL)
GVAR(SDK::IGameEventManager2*, pGameEventMgr, NULL)
GVAR(SDK::IInputSystem*, pInputSystem, NULL)
GVAR(bool, bIsMenuShown, false)



