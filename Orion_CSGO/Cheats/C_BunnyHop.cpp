#include "../OrionIncludes.h"

C_BunnyHop::C_BunnyHop(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bInitialized = true;
}

C_BunnyHop::~C_BunnyHop()
{
  
}

void C_BunnyHop::Perform(SDK::CUserCmd* pCmd)
{
  if (m_bInitialized)
  {
    if (m_bEnabled)
    {
      if (!(pLocalPlayer->GetFlags() & FL_ONGROUND))
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

bool C_BunnyHop::UndoChanges()
{
  return true;
}



