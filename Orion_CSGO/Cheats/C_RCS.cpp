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
    if (G::pEngine)
    {
      if (G::pMe)
      {
        Engine::CBaseWeapon* pWeapon = G::pMe->GetBaseWeapon();
        if (pWeapon)
        {
          if (G::pGlobals)
          {
            float NextAttack = pWeapon->GetNextPrimaryAttack();
            float Tick = G::pMe->GetTickBase() * G::pGlobals->interval_per_tick;

            if (pCmd->buttons & IN_ATTACK || pCmd->buttons & IN_ATTACK2)
            {
              SDK::Vector vCurrentPunch = *G::pMe->GetAimPunchAngle() * 2.0f;
              SDK::Vector vPunchDiff = m_vOldPunch - vCurrentPunch;
              
              if (vPunchDiff.Length2D() < 2.0f)
              {
                pCmd->viewangles += vPunchDiff;
                Utils::AngleNormalize(pCmd->viewangles);
              }
              m_vOldPunch = vCurrentPunch;
            }
            else
            {
              if (NextAttack < Tick)
              {
                pCmd->viewangles += *G::pMe->GetAimPunchAngle() / 11.3f;// = (pCmd->viewangles + *G::pMe->GetAimPunchAngle() * 2.0f) / 2;
                m_vOldPunch.Init();
              }
            }
          }
        }
      }
    }
  }
}

void C_RCS::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable RCS"), &m_bEnabled);
  if (m_bEnabled)
  {

  }
}

void C_RCS::OnDraw()
{

}

bool C_RCS::UndoChanges()
{
  return true;
}

bool C_RCS::UndoDraws()
{
  return true;
}

