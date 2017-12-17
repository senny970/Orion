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
GVAR(SDK::CUserCmd*, pCmd, nullptr)
GVAR(SDK::IMaterial*, pVisibleTexture, nullptr)
GVAR(SDK::IMaterial*, pHiddenTexture, nullptr)
GVAR(SDK::IMaterial*, pVisibleFlat, nullptr)
GVAR(SDK::IMaterial*, pHiddenFlat, nullptr)
GVAR(Engine::CBaseEntity*, pMe, nullptr)
GVAR(Engine::CRender*, pRender, nullptr)
GVAR(int, iScreenWidth, 0)
GVAR(int, iScreenHeight, 0)
GVAR(bool, bIsMenuShown, false)
GVAR(bool, bSendPacket, true)
GVAR(LineGoesThroughSmokeFn, LinesGoesThroughSmoke, nullptr)
GVAR(InitKeyValuesFn, InitKeyValues, nullptr)
GVAR(LoadFromBufferFn, LoadFromBuffer, nullptr)
GVAR(DWORD, pGlowManager, NULL)

