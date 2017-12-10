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
    
  }
}

bool C_Radar::OnDraw()
{
  return true;
}

bool C_Radar::UndoChanges()
{
  return true;
}



