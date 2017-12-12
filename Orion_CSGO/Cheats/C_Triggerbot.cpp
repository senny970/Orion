#include "../OrionIncludes.h"

C_Triggerbot::C_Triggerbot(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_flWallShootChance = 0.0f;
}

C_Triggerbot::~C_Triggerbot()
{

}

void C_Triggerbot::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    SDK::Vector vAngle = pCmd->viewangles + pMe->GetAimPunchAngle() * 2;

    SDK::Vector	vStart, vStop, vForward;

    Utils::AngleVectors(vAngle, vForward);

    Engine::CBaseWeapon* pWeapon = pMe->GetBaseWeapon();
    //CWeaponInfo* pWeaponInfo = pWeapon->GetWeaponInfo();

    //if (pWeaponInfo)
    //{
    //  vForward *= pWeaponInfo->m_flRange;
    //}
    
    vForward *= 8192.0f;

    vStart = pMe->GetEyePosition();
    vStop = vStart + vForward;

    SDK::Ray_t ray;
    SDK::trace_t tr;
    SDK::CTraceFilter filter;
    filter.pSkip = pMe;

    ray.Init(vStart, vStop);

    G::pEngineTrace->TraceRay(ray, PlayerVisibleMask, &filter, &tr);

    cout << tr.fraction << endl;

    int hitgroup = tr.hitgroup;

    if (hitgroup > 0)//== SDK::HITGROUP_CHEST || hitgroup == SDK::HITGROUP_HEAD)
    {
      for each (Engine::CBaseEntity* pEnemy in m_vEnemies)
      {
        if (pEnemy->IsAlive())
        {
          if (tr.m_pEnt == pEnemy || tr.fraction > m_flWallShootChance)
          {
            float NextAttack = pWeapon->GetNextPrimaryAttack();
            float Tick = pMe->GetTickBase() * G::pGlobals->interval_per_tick;

            if (NextAttack < Tick)
            {
              if (*pWeapon->GeteAttributableItem()->GetItemDefinitionIndex() == Engine::WEAPON_REVOLVER)
              {
                pCmd->buttons |= IN_ATTACK2;
              }
              else
              {
                pCmd->buttons |= IN_ATTACK;
              }
              continue;
            }

            if (*pWeapon->GeteAttributableItem()->GetItemDefinitionIndex() == Engine::WEAPON_REVOLVER)
            {
              pCmd->buttons &= ~IN_ATTACK2;
            }
            else
            {
              pCmd->buttons &= ~IN_ATTACK;
            }

            //for (int i = 0; i < 150; i++)
            //{
            //  if (G::pInput->m_pVerifiedCommands[i].m_cmd.command_number == pCmd->command_number)
            //  {
            //    G::pInput->m_pVerifiedCommands[i].m_cmd = *pCmd;
            //    G::pInput->m_pVerifiedCommands[i].m_crc = pCmd->GetChecksum();
            //  }
            //}
          }
        }
      }
    }
  }
}

void C_Triggerbot::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable triggerbot"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::SliderFloat(XS("Ignore walls"), &m_flWallShootChance, 0.0f, 1.0f, XS("%.4f"));
    
  }
}

void C_Triggerbot::OnDraw()
{

}

bool C_Triggerbot::UndoChanges()
{
  return true;
}



