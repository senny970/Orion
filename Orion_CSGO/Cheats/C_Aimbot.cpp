#include "../OrionIncludes.h"

C_Aimbot::C_Aimbot(const string& sCheatName)
  : C_Cheat(sCheatName)
{

}

C_Aimbot::~C_Aimbot()
{

}

void C_Aimbot::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {

  }
}

void C_Aimbot::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable aimbot"), &m_bEnabled);
}

void C_Aimbot::OnDraw()
{

}

bool C_Aimbot::UndoChanges()
{
  return true;
}



