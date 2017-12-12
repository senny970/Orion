#include "../OrionIncludes.h"

C_RCS::C_RCS(const string& sCheatName)
  : C_Cheat(sCheatName)
{

}

C_RCS::~C_RCS()
{

}

void C_RCS::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (pCmd->buttons & IN_ATTACK)
    {
      SDK::QAngle aimpunch = pMe->GetAimPunchAngle() * 2;

      pCmd->viewangles += (m_vOldAngle - aimpunch);

      m_vOldAngle = aimpunch;
    }
    else
    {
      m_vOldAngle.Init();
    }
  }
}

void C_RCS::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable RCS"), &m_bEnabled);
}

void C_RCS::OnDraw()
{

}

bool C_RCS::UndoChanges()
{
  return true;
}



