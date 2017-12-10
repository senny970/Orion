#include "../OrionIncludes.h"

C_Bhop::C_Bhop(const string& sCheatName)
  : C_Cheat(sCheatName)
{

}

C_Bhop::~C_Bhop()
{
  
}

void C_Bhop::Perform(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (!(pMe->GetFlags() & FL_ONGROUND))
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

bool C_Bhop::UndoChanges()
{
  return true;
}



