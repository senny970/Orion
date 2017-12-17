#include "../OrionIncludes.h"

C_Bhop::C_Bhop(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bAutoStrafe = false;
}

C_Bhop::~C_Bhop()
{

}

void C_Bhop::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (G::pEngine)
    {
      if (G::pMe && G::pMe->IsAlive() && G::pMe->GetTeam() != Engine::TEAM_SPEC)
      {
        if (!(G::pMe->GetFlags() & FL_ONGROUND))
        {
          if (pCmd->buttons & IN_JUMP)
          {
            pCmd->buttons &= ~IN_JUMP;
          }
          if (m_bAutoStrafe)
          {
            if (pCmd->mousedx < 0)
            {
              pCmd->sidemove = -450.0f;
            }
            else if (pCmd->mousedx > 0)
            {
              pCmd->sidemove = 450.0f;
            }
          }
        }
      }
    }
  }
}

void C_Bhop::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable bunnyhop"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::Checkbox(XS("Autostrafe"), &m_bAutoStrafe);
  }
}

void C_Bhop::OnDraw()
{

}

bool C_Bhop::UndoChanges()
{
  return true;
}

bool C_Bhop::UndoDraws()
{
  return true;
}

