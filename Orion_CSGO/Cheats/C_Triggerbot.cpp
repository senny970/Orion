#include "../OrionIncludes.h"

C_Triggerbot::C_Triggerbot(const string& sCheatName)
  : C_Cheat(sCheatName)
{

}

C_Triggerbot::~C_Triggerbot()
{

}

void C_Triggerbot::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {

  }
}

void C_Triggerbot::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable triggerbot"), &m_bEnabled);
}

void C_Triggerbot::OnDraw()
{

}

bool C_Triggerbot::UndoChanges()
{
  return true;
}



