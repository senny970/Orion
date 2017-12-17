#include "OrionIncludes.h"

JUNKGEN(0);

LRESULT __stdcall H::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  if (GetAsyncKeyState(ORION_MENU_BTN))
  {
    G::bIsMenuShown = !G::bIsMenuShown;
    ImGui::GetIO().MouseDrawCursor = G::bIsMenuShown;
    
    if (G::pEngine)
    {
      string sConsoleCMD = XS("cl_mouseenable ") + to_string(!G::bIsMenuShown);
      G::pEngine->ClientCmd_Unrestricted2(sConsoleCMD.c_str());
    }

    Beep(700, 100);
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
  DWORD dwOld_D3DRS_COLORWRITEENABLE;

  /*this is so we can draw without net_graph*/
  thisptr->GetRenderState(D3DRS_COLORWRITEENABLE, &dwOld_D3DRS_COLORWRITEENABLE);
  thisptr->SetRenderState(D3DRS_COLORWRITEENABLE, 0xffffffff);

  if (G::pEngine)
  {
    G::pEngine->GetScreenSize(G::iScreenWidth, G::iScreenHeight);    
    
    map<string, C_Cheat*> mapCheats = CM::GetCheats();

    if (!G::pEngine->IsTakingScreenshot())
    {
      if (G::pRender)
      {          
        G::pRender->BeginRender();
      }

      //if (G::pEngine->IsInGame())
      //{
      //  G::pRender->Text(3, 3, false, true, SDK::Color::Orange(), ORION_HACK_NAME);
      //}

      ImGui_ImplDX9_NewFrame();

      if (G::bIsMenuShown)
      {
        if (ImGui::Begin(XS("Orion Hooks Menu"), 0,
          ImGuiWindowFlags_NoCollapse
          //| ImGuiWindowFlags_NoResize
        ))
        {
          for (auto it = mapCheats.begin(); it != mapCheats.end(); ++it)
          {
            it->second->OnDrawMenu();
          }

          ImGui::End();
        }
      }

      //for (auto it = mapCheats.begin(); it != mapCheats.end(); ++it)
      //{
      //  it->second->OnDraw();
      //}

      GET_CHEAT(C_Visuals, pVisuals);
      if (pVisuals)
      {
        pVisuals->OnDraw();
      }

      ImGui::Render();

      if (G::pRender)
      {
        G::pRender->EndRender();
      }
    }
    else
    {
      //for (auto it = mapCheats.begin(); it != mapCheats.end(); ++it)
      //{
      //  it->second->UndoDraws();
      //}
    }
  }

  thisptr->SetRenderState(D3DRS_COLORWRITEENABLE, dwOld_D3DRS_COLORWRITEENABLE);

  return U::VMTHookMgr::GetHook(XS("D3D_EndScene"))->
    GetOriginFn<IDirect3DDevice9_EndSceneFn>()(thisptr);
}

HRESULT __stdcall H::D3D_Reset(
  IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
  if (G::pRender)
  {
    G::pRender->OnLostDevice();
  }
  
  ImGui_ImplDX9_InvalidateDeviceObjects();

  HRESULT hRes = U::VMTHookMgr::GetHook(XS("D3D_Reset"))->
    GetOriginFn<IDirect3DDevice9_ResetFn>()(thisptr, pPresentationParameters);

  if (G::pRender)
  {
    G::pRender->OnResetDevice();
  }
  
  ImGui_ImplDX9_CreateDeviceObjects();

  return hRes;
}

bool __stdcall H::IClientMode_CreateMove(
  float flInputSampleTime, SDK::CUserCmd* pCmd)
{
  if (pCmd->command_number == 0)
  {
    G::pMe = nullptr;
    return false;
  }  
  
  G::pCmd = pCmd;
  if (G::pEngine && G::pEntityList)
  {    
    G::pMe = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());
  }

  GET_CHEAT(C_Bhop, pBhop);
  GET_CHEAT(C_FakeLag, pFakelag);
  GET_CHEAT(C_Radar, pRadar);
  GET_CHEAT(C_Triggerbot, pTBot);
  GET_CHEAT(C_RCS, pRCS);
  //GET_CHEAT(C_Aimbot, pABot);

  if (pBhop)
  {
    pBhop->OnCreateMove(pCmd);
  }

  if (pFakelag)
  {
    pFakelag->OnCreateMove(pCmd);
  }

  if (pRadar)
  {
    pRadar->UpdateEntities();
    pRadar->OnCreateMove(pCmd);
  }

  //if (pABot)
  //{
  //  JUNKCODE(0);
  //  
  //  
  //  pABot->UpdateEntities();
  //  pABot->OnCreateMove(pCmd);
  //}

  if (pTBot)
  {
    pTBot->UpdateEntities();
    pTBot->OnCreateMove(pCmd);
  }
  if (pRCS)
  {
    //if (!pVisuals || (pVisuals && !pVisuals->m_bNoRecoil))
    {
      pRCS->OnCreateMove(pCmd);
    }
  }

  //if (pVisuals)
  //{
  //  if (pVisuals->m_bNoRecoil)
  //  {
  //    if (G::pMe)
  //    {
  //      pCmd->viewangles -= *G::pMe->GetAimPunchAngle() * 2.0f;
  //      JUNKCODE(0);
  //      return false;
  //    }
  //  }
  //  pVisuals->UpdateEntities();
  //  pVisuals->OnCreateMove(pCmd);
  //}

  //G::pEngine->SetViewAngles(pCmd->viewangles);

  //return false;
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

void __fastcall H::IVModelRender_DrawModelExecute(SDK::IVModelRender* thisptr,
  void* pEdx, SDK::IMatRenderContext* context,
  const SDK::DrawModelState_t &state, const SDK::ModelRenderInfo_t& info,
  SDK::matrix3x4_t* pCustomBoneToWorld)
{
  GET_CHEAT(C_Chams, pChams);

  if (G::pEngine)
  {
    if (!G::pEngine->IsTakingScreenshot())
    {
      if (info.pModel)
      {
        if (context && pCustomBoneToWorld)
        {
          if (pChams)
          {
            pChams->OnDrawModel(thisptr, pEdx, context, state, info, pCustomBoneToWorld);
          }
        }
      }
    }
    else
    {

    }
  }

  U::VMTHookMgr::GetHook(XS("IVModelRender_DrawModelExecute"))->
    GetOriginFn<IVModelRender_DrawModelExecuteFn>()(
      thisptr, pEdx, context, state,info, pCustomBoneToWorld);

  if (G::pEngine)
  {
    if (!G::pEngine->IsTakingScreenshot())
    {
      if (context && pCustomBoneToWorld)
      {
        if (G::pModelRender)
        {
          if (pChams && pChams->IsEnabled())
          {
            G::pModelRender->ForcedMaterialOverride(NULL);
          }
        }
      }
    }
  }
}

void __stdcall H::IBaseClientDll_FrameStageNotify(SDK::ClientFrameStage_t stage)
{
  GET_CHEAT(C_Visuals, pVisuals);
  if (pVisuals)
  {
    pVisuals->OnFrameStageNotify(stage);
  }

  U::VMTHookMgr::GetHook(XS("IBaseClientDll_FrameStageNotify"))->
    GetOriginFn<IBaseClientDll_FrameStageNotifyFn>()(stage);

  if (stage == SDK::ClientFrameStage_t::FRAME_RENDER_START)
  {
    GET_CHEAT(C_Glowhack, pGlow);

    if (pGlow)
    {
      pGlow->UpdateEntities();
      pGlow->OnDraw();
    }
  }

  if (pVisuals)
  {
    pVisuals->AfterFrameStageNotify(stage);
  }
}




