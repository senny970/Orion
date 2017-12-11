#include "../OrionIncludes.h"

C_Radar::C_Radar(const string& sCheatName)
  : C_Cheat(sCheatName)
{

}

C_Radar::~C_Radar()
{

}

void C_Radar::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    for each (Engine::CBaseEntity* pEnemy in m_vEnemies)
    {
      *pEnemy->IsSpotted() = true;
    }
  }
}

void C_Radar::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable radarhack"), &m_bEnabled);
}

void C_Radar::OnDraw()
{

}

bool C_Radar::UndoChanges()
{
  return true;
}



