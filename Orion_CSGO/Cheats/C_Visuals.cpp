#include "../OrionIncludes.h"

C_Visuals::C_Visuals(const string& sCheatName)
  : C_Cheat(sCheatName)/*,
    pvAimPunch(nullptr),
    pvViewPunch(nullptr)*/
{
  m_bNoFlashEnabled = false;
  //m_bNoRecoil = false;
  m_bDrawCrossHair = false;
  m_bDynamicCrosshair = false;

  m_iCrosshairSize = 5;
}

C_Visuals::~C_Visuals()
{

}

void C_Visuals::OnCreateMove(SDK::CUserCmd* pCmd)
{

}

void C_Visuals::OnDrawMenu()
{
  ImGui::Checkbox(XS("No flash"), &m_bNoFlashEnabled);
  //ImGui::Checkbox(XS("No recoil"), &m_bNoRecoil);
  ImGui::Checkbox(XS("Draw crosshair"), &m_bDrawCrossHair);

  if (m_bDrawCrossHair)
  {
    ImGui::Checkbox(XS("Dynamic crosshair"), &m_bDynamicCrosshair);
    ImGui::SliderInt(XS("Crosshair Size"), &m_iCrosshairSize, 1, 10);
  }
}

void C_Visuals::OnFrameStageNotify(SDK::ClientFrameStage_t stage)
{
  if (G::pEngine && G::pEngine->IsInGame())
  {
    //if (m_bNoRecoil)
    //{
    //  if (stage == SDK::ClientFrameStage_t::FRAME_RENDER_START)
    //  {
    //    if (G::pMe && G::pMe->IsAlive())
    //    {
    //      JUNKCODE(0);
    //      
    //      //for (int i = 1; i <= G::pGlobals->maxClients; i++)
    //      //{
    //      //  JUNKCODE(0);
    //      //  if (i != G::pEngine->GetLocalPlayer())
    //      //  {
    //      //    JUNKCODE(0);
    //      //    Engine::CBaseEntity* pCurEntity = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(i);
    //      //    JUNKCODE(0);
    //      //    
    //      //    if (pCurEntity)
    //      //    {
    //      //      *(int*)((DWORD)pCurEntity + 0xA28) = 0;
    //      //      JUNKCODE(0);
    //      //      *(int*)((DWORD)pCurEntity + 0xA30) = G::pGlobals->framecount;
    //      //      JUNKCODE(0);
    //      //    }
    //      //  }
    //      //}
    //      //*(int*)((DWORD)G::pMe + 0xA28) = 0;
    //      //JUNKCODE(0);
    //      //*(int*)((DWORD)G::pMe + 0xA30) = G::pGlobals->framecount;
    //      //JUNKCODE(0);
    //      
    //      
    //      pvViewPunch = G::pMe->GetViewPunchAngle();
    //      JUNKCODE(0);
    //      pvAimPunch = G::pMe->GetAimPunchAngle();
    //      JUNKCODE(0);
    //      
    //      
    //      vViewPunchOld = *pvViewPunch;
    //      JUNKCODE(0);
    //      vAimPunchOld = *pvAimPunch;
    //      JUNKCODE(0);
    //      
    //      
    //      *pvViewPunch = SDK::Vector(0, 0, 0);
    //      JUNKCODE(0);
    //      *pvAimPunch = SDK::Vector(0, 0, 0);
    //      JUNKCODE(0);
    //    }
    //  }
    //}
  }
}

void C_Visuals::AfterFrameStageNotify(SDK::ClientFrameStage_t stage)
{

  if (stage == SDK::ClientFrameStage_t::FRAME_RENDER_START)
  {
    if (m_bNoFlashEnabled)
    {
      if (G::pEngine)
      {
        if (G::pEngine->IsInGame())
        {
          if (G::pMe)
          {
            *G::pMe->GetFlashDuration() = 0.0f;
          }
        }
      }
    }
  }

  //if (G::pEngine)
  //{
  //  if (m_bNoRecoil)
  //  {
  //    if (pvAimPunch)
  //    {
  //      JUNKCODE(0);
  //      
  //      *pvAimPunch = vAimPunchOld;
  //      JUNKCODE(0);
  //      
  //    }
  //    if (pvViewPunch)
  //    {
  //      JUNKCODE(0);
  //      
  //      *pvViewPunch = vViewPunchOld;
  //      JUNKCODE(0);
  //      
  //    }
  //    JUNKCODE(0);
  //    
  //    vAimPunchOld.Init();
  //    JUNKCODE(0);
  //    
  //    vViewPunchOld.Init();
  //    JUNKCODE(0);
  //    
  //    pvAimPunch = nullptr;
  //    JUNKCODE(0);
  //    
  //    pvViewPunch = nullptr;
  //    JUNKCODE(0);
  //    
  //  }
  //}
}

void C_Visuals::OnDraw()
{
  if (G::pEngine)
  {
    if (m_bDrawCrossHair)
    {
      if (G::pMe)
      {
        SDK::Vector vPunchAngle(0.0f, 0.0f, 0.0f);

        if (m_bDynamicCrosshair)
        {
          vPunchAngle = *G::pMe->GetAimPunchAngle();
        }

        float flScreenSizeDependence = (float)G::iScreenHeight / 100;
        int punch_x = (int)G::iScreenWidth / 2 + (int)(vPunchAngle.y * -flScreenSizeDependence);
        int punch_y = (int)G::iScreenHeight / 2 + (int)(vPunchAngle.x * flScreenSizeDependence);

        SDK::Color crosshairColor = SDK::Color::Green();
        G::pRender->DrawLine(punch_x - m_iCrosshairSize, punch_y, punch_x + m_iCrosshairSize + 1, punch_y, crosshairColor);
        G::pRender->DrawLine(punch_x, punch_y - m_iCrosshairSize, punch_x, punch_y + m_iCrosshairSize + 1, crosshairColor);
      }
    }
  }
}

bool C_Visuals::UndoChanges()
{
  return true;
}

bool C_Visuals::UndoDraws()
{
  return true;
}



