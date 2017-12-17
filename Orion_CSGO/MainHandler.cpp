#include "OrionIncludes.h"

void M::InitGlobals(HINSTANCE hDllInstance)
{
  G::hDllInstance = hDllInstance;
  G::hCurentWindow = FindWindow(NULL, ORION_WINDOW_NAME);
  G::pD3D = U::GetD3D();
  G::bSendPacket = true;

  void* pEngineIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("engine.dll")), XS("CreateInterface")));
  if (pEngineIFace)
  {
    G::pEngine = U::FindIFace<SDK::IVEngineClient*>(pEngineIFace, XS("VEngineClient"));
    //while (!G::pEngine->IsInGame()) S_MS(100);
    G::pEngineTrace = U::FindIFace<SDK::IEngineTrace*>(pEngineIFace, XS("EngineTraceClient"));
    G::pModelInfo = U::FindIFace<SDK::IVModelInfoClient*>(pEngineIFace, XS("VModelInfoClient"));
    G::pSound = U::FindIFace<SDK::IEngineSound*>(pEngineIFace, XS("IEngineSoundClient"));
    G::pModelRender = U::FindIFace<SDK::IVModelRender*>(pEngineIFace, XS("VEngineModel"));
    G::pRenderView = U::FindIFace<SDK::IVRenderView*>(pEngineIFace, XS("VEngineRenderView"));
    G::pGameEventMgr = U::FindIFace<SDK::IGameEventManager2*>(pEngineIFace, XS("GAMEEVENTSMANAGER"));
  }

  void* pClientIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("client.dll")), XS("CreateInterface")));
  if (pClientIFace)
  {
    G::pClient = U::FindIFace<SDK::IBaseClientDLL*>(pClientIFace, XS("VClient"));
    G::pEntityList = U::FindIFace<SDK::IClientEntityList*>(pClientIFace, XS("VClientEntityList"));
  }

  void* pMatSysIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("materialsystem.dll")), XS("CreateInterface")));
  if (pMatSysIFace)
  {
    G::pMaterialSystem = U::FindIFace<SDK::IMaterialSystem*>(pMatSysIFace, XS("VMaterialSystem"));
  }

  void* pVGUIMatSurfIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("vguimatsurface.dll")), XS("CreateInterface")));
  if (pVGUIMatSurfIFace)
  {
    G::pSurface = U::FindIFace<SDK::ISurface*>(pVGUIMatSurfIFace, XS("VGUI_Surface"));
  }

  void* pInputSysIFace = (void*)(GetProcAddress(U::GetModHandle(
    XS("inputsystem.dll")), XS("CreateInterface")));
  if (pInputSysIFace)
  {
    G::pInputSystem = U::FindIFace<SDK::IInputSystem*>(pInputSysIFace, XS("InputSystemVersion"));
  }

  G::LinesGoesThroughSmoke = U::FindPattern<LineGoesThroughSmokeFn>(XS("client.dll"),
    XS("55 8B EC 83 EC 08 8B 15 ?? ?? ?? ?? 0F 57 C0"), XS("G::LinesGoesThroughSmoke"), 0);

  G::pGlowManager = *U::FindPattern<DWORD*>(XS("client.dll"),
    XS("0F 11 05 ?? ?? ?? ?? 83 C8 01 C7 05 ?? ?? ?? ?? 00 00 00 00"),
    XS("G::pGlowManager"), 3);

  if (!G::InitKeyValues)
  {
    G::InitKeyValues = U::FindPattern<InitKeyValuesFn>(XS("client.dll"),
      XS("55 8B EC 51 33 C0 C7 45"), XS("G::InitKeyValues"), 0);
    //G::InitKeyValues = U::FindPattern<InitKeyValuesFn>(XS("client.dll"),
    //XS("FF 52 24 8B 0E 33 4D FC 81 E1 ?? ?? ?? ?? 31 0E 88 46 03 C1 F8 08 66 89 46 12 8B C6"),
    //XS("G::InitKeyValues"), -0x42);
  }

  if (!G::LoadFromBuffer)
  {
    G::LoadFromBuffer = U::FindPattern<LoadFromBufferFn>(XS("client.dll"),
      XS("55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04"),
      XS("G::LoadFromBuffer"), 0);
  }

  if (G::pClient)
  {
    G::pGlobals = **(SDK::CGlobalVarsBase***)(((uint32_t**)G::pClient)[0][0] + 0x1B);
    G::pInput = **(SDK::CInput***)(((uint32_t**)G::pClient)[0][15] + 0x1);
    G::pClientMode = **(SDK::IClientMode***)(((uint32_t**)G::pClient)[0][10] + 0x5);
  }
  if (G::pD3D)
  {
    G::pRender = new Engine::CRender(G::pD3D);
  }

  if (!G::pVisibleFlat)
  {
    G::pVisibleFlat = Utils::CreateMaterial(true, false, false);
  }
  if (!G::pVisibleTexture)
  {
    G::pVisibleTexture = Utils::CreateMaterial(false, false, false);
  }
  if (!G::pHiddenFlat)
  {
    G::pHiddenFlat = Utils::CreateMaterial(true, true, false);
  }
  if (!G::pHiddenTexture)
  {
    G::pHiddenTexture = Utils::CreateMaterial(false, true, false);
  }
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

  U::JMPHookMgr::RegHook(XS("pSendPacket"), U::FindPattern(XS("engine.dll"),
    XS("B3 01 8B 01 8B 40"), XS("pSendPacket"), 2), 5, H::CHLClient_CreateMove,
    U::JMPHook::JMPTypes::JMPType_Call, false);
  U::JMPHookMgr::ApplyHook(XS("pSendPacket"));

  U::VMTHookMgr::RegHook(G::pD3D, U::VMTS::D3D::EndScene,
    H::D3D_EndScene, XS("D3D_EndScene"));
  U::VMTHookMgr::ApplyHook(XS("D3D_EndScene"));

  U::VMTHookMgr::RegHook(G::pD3D, U::VMTS::D3D::Reset,
    H::D3D_Reset, XS("D3D_Reset"));
  U::VMTHookMgr::ApplyHook(XS("D3D_Reset"));

  U::VMTHookMgr::RegHook(G::pClientMode, SDK::VMTS::IClientMode::CreateMove,
    H::IClientMode_CreateMove, XS("IClientMode_CreateMove"));
  U::VMTHookMgr::ApplyHook(XS("IClientMode_CreateMove"));

  U::VMTHookMgr::RegHook(G::pClient, SDK::VMTS::IBaseClientDLL::CreateMove,
    H::IBaseClientDll_CreateMove, XS("IBaseClientDll_CreateMove"));
  U::VMTHookMgr::ApplyHook(XS("IBaseClientDll_CreateMove"));

  U::VMTHookMgr::RegHook(G::pClient, SDK::VMTS::IBaseClientDLL::FrameStageNotify,
    H::IBaseClientDll_FrameStageNotify, XS("IBaseClientDll_FrameStageNotify"));
  U::VMTHookMgr::ApplyHook(XS("IBaseClientDll_FrameStageNotify"));

  U::VMTHookMgr::RegHook(G::pModelRender, SDK::VMTS::IVModelRender::DrawModelExecute,
    H::IVModelRender_DrawModelExecute, XS("IVModelRender_DrawModelExecute"));
  U::VMTHookMgr::ApplyHook(XS("IVModelRender_DrawModelExecute"));
}

void M::InitEngine()
{
  Engine::g_NetVar.Init(G::pClient->GetAllClasses());
  Engine::Offset::Initialize();
}

void M::RegCheats()
{
  REG_CHEAT(C_Bhop);
  REG_CHEAT(C_FakeLag);
  REG_CHEAT(C_Radar);
  REG_CHEAT(C_Glowhack);
  REG_CHEAT(C_Triggerbot);
  REG_CHEAT(C_RCS);
  REG_CHEAT(C_Chams);
  REG_CHEAT(C_Visuals);
  //REG_CHEAT(C_Aimbot);
}

void M::InitAll(HINSTANCE hDllInstance)
{
#ifdef _DEBUG
  U::bDebug = true;
  U::OpenConsole(string(ORION_HACK_NAME) + XS(" ") + string(ORION_VERSION) + XS(" DEBUG"));
#endif
#ifdef NDEBUG
  U::bDebug = false;
  U::OpenConsole(string(ORION_HACK_NAME) + XS(" ") + string(ORION_VERSION));
#endif

  InitGlobals(hDllInstance);
  InitImGui();
  InitHooks();
  InitEngine();
  
  RegCheats();

  Beep(700, 500);

  while (!GetAsyncKeyState(ORION_UNINJECT_BTN))
  {
    if (!G::pEngine || !G::pEngine->IsInGame())
    {
      G::pMe = nullptr;
    }
    Sleep(10);
  }

  ReleaseAll();
}

void M::ReleaseAll()
{
  G::pEngine->ClientCmd_Unrestricted2(XS("cl_mouseenable 1"));

  delete U::JMPHookMgr::Instance();
  delete U::VMTHookMgr::Instance();
  delete U::PatchMgr::Instance();
  delete CM::Instance();

  delete G::pRender;

  ImGui_ImplDX9_Shutdown();

  SetWindowLongPtr(G::hCurentWindow, GWL_WNDPROC, (LONG)G::oWndProc);

  U::CloseConsole();

  Beep(800, 100);

  FreeLibraryAndExitThread((HMODULE)G::hDllInstance, 0);
}
