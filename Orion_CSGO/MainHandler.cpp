#include "OrionIncludes.h"

void M::InitGlobals(HINSTANCE hDllInstance)
{
  G::hDllInstance = hDllInstance;
  G::hCurentWindow = FindWindow(NULL, ORION_WINDOW_NAME);
  G::pD3D = U::GetD3D();

  void* pEngineIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("engine.dll")), XS("CreateInterface")));
  G::pEngine = U::FindIFace<SDK::IVEngineClient*>(pEngineIFace, XS("VEngineClient"));
  G::pEngineTrace = U::FindIFace<SDK::IEngineTrace*>(pEngineIFace, XS("EngineTraceClient"));
  G::pModelInfo = U::FindIFace<SDK::IVModelInfoClient*>(pEngineIFace, XS("VModelInfoClient"));
  G::pSound = U::FindIFace<SDK::IEngineSound*>(pEngineIFace, XS("IEngineSoundClient"));
  G::pModelRender = U::FindIFace<SDK::IVModelRender*>(pEngineIFace, XS("VEngineModel"));
  G::pRenderView = U::FindIFace<SDK::IVRenderView*>(pEngineIFace, XS("VEngineRenderView"));
  G::pGameEventMgr = U::FindIFace<SDK::IGameEventManager2*>(pEngineIFace, XS("GAMEEVENTSMANAGER"));

  void* pClientIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("client.dll")), XS("CreateInterface")));
  G::pClient = U::FindIFace<SDK::IBaseClientDLL*>(pClientIFace, XS("VClient"));
  G::pEntityList = U::FindIFace<SDK::IClientEntityList*>(pClientIFace, XS("VClientEntityList"));
  G::pGlobals = **(SDK::CGlobalVarsBase***)((*(uint32_t**)G::pClient)[0] + 0x1B);
  G::pInput = **(SDK::CInput***)((*(uint32_t**)G::pClient)[15] + 0x1);
  G::pClientMode = **(SDK::IClientMode***)((*(uint32_t**)G::pClient)[10] + 0x5);

  void* pMatSysIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("materialsystem.dll")), XS("CreateInterface")));
  G::pMaterialSystem = U::FindIFace<SDK::IMaterialSystem*>(pMatSysIFace, XS("VMaterialSystem"));

  void* pVGUIMatSurfIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("vguimatsurface.dll")), XS("CreateInterface")));
  G::pSurface = U::FindIFace<SDK::ISurface*>(pVGUIMatSurfIFace, XS("VGUI_Surface"));

  void* pInputSysIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("inputsystem.dll")), XS("CreateInterface")));
  G::pInputSystem = U::FindIFace<SDK::IInputSystem*>(pInputSysIFace, XS("InputSystemVersion"));
}

void M::InitImGui()
{
  ImGui_ImplDX9_Init(G::hCurentWindow, G::pD3D);
  ImGui_ImplDX9_CreateDeviceObjects();
}

void M::InitHooks()
{
  G::oWndProc = (WNDPROC)SetWindowLongPtr(G::hCurentWindow,
    GWL_WNDPROC, (LONG)H::WndProc);

  U::VMTHookMgr::RegHook(G::pD3D, U::VMTHook::Tables::D3D_EndScene,
    H::D3D_EndScene, XS("D3D_EndScene"));
  U::VMTHookMgr::ApplyHook(XS("D3D_EndScene"));

  U::VMTHookMgr::RegHook(G::pD3D, U::VMTHook::Tables::D3D_Reset,
    H::D3D_Reset, XS("D3D_Reset"));
  U::VMTHookMgr::ApplyHook(XS("D3D_Reset"));

  U::VMTHookMgr::RegHook(G::pClientMode, 24,
    H::IClientMode_CreateMove, XS("IClientMode_CreateMove"));
  U::VMTHookMgr::ApplyHook(XS("IClientMode_CreateMove"));
}

void M::RegCheats()
{
#define REG_CHEAT(CHEAT) C_CheatMgr::RegCheat(new CHEAT(XS("" #CHEAT)), XS("" #CHEAT));
  REG_CHEAT(C_BunnyHop);
}

void M::InitAll(HINSTANCE hDllInstance)
{
  U::OpenConsole(string(ORION_TITLE) + string(ORION_VERSION));

  InitGlobals(hDllInstance);
  InitImGui();
  InitHooks();
  RegCheats();

  Engine::g_NetVar.Init(G::pClient->GetAllClasses());
  Engine::Offset::Initialize();

  Beep(700, 500);

  while (!GetAsyncKeyState(VK_F1))
  {
    Sleep(10);
  }

  ReleaseAll();
}

void M::ReleaseAll()
{
  G::pEngine->ClientCmd_Unrestricted2(XS("cl_mouseenable 1"));

  ImGui_ImplDX9_Shutdown();

  delete U::JMPHookMgr::Instance();
  delete U::PatchMgr::Instance();
  delete U::VMTHookMgr::Instance();

  SetWindowLongPtr(G::hCurentWindow, GWL_WNDPROC, (LONG)G::oWndProc);

  U::CloseConsole();

  Beep(800, 200);
  Beep(800, 200);

  FreeLibraryAndExitThread((HMODULE)G::hDllInstance, 0);
}
