#include "../OrionIncludes.h"

JUNKGEN(0);

C_Triggerbot::C_Triggerbot(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bAutoTrigger = true;
  m_bShotEnemies = true;
  m_bShotFriendlies = false;
  m_bTriggerHead = true;
  m_bTriggerBody = true;
  m_bTriggerLegsArms = true;
  m_iKeyUse = 0;
}

C_Triggerbot::~C_Triggerbot()
{

}

void C_Triggerbot::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (G::pEngine)
    {
      int iKeyUse = VK_MENU;
      if (m_iKeyUse == 1) iKeyUse = VK_SHIFT;

      if (m_bAutoTrigger || GetAsyncKeyState(iKeyUse) & 0x8000)
      {
        if (G::pMe && G::pMe->IsAlive())
        {          
          SDK::Vector vAngle = pCmd->viewangles + *G::pMe->GetAimPunchAngle() * 2;

          SDK::Vector	vStart, vStop, vForward;

          Utils::AngleVectors(vAngle, vForward);

          Engine::CBaseWeapon* pWeapon = G::pMe->GetBaseWeapon();
          if (pWeapon)
          {
            CWeaponInfo* pWeaponInfo = pWeapon->GetWeaponInfo();
            if (pWeaponInfo)
            {              
              vForward *= pWeaponInfo->m_flRange;
            }
          }
          vForward *= 8192.0f;

          vStart = G::pMe->GetEyePosition();

          vStop = vStart + vForward;

          SDK::Ray_t ray;
          SDK::trace_t tr;
          SDK::CTraceFilter filter;
          filter.pSkip = G::pMe;

          ray.Init(vStart, vStop);

          G::pEngineTrace->TraceRay(ray, PlayerVisibleMask, &filter, &tr);

          int hitgroup = tr.hitgroup;

          if (hitgroup == SDK::HITGROUP_HEAD && m_bTriggerHead
              || (hitgroup == SDK::HITGROUP_CHEST
                || hitgroup == SDK::HITGROUP_STOMACH) && m_bTriggerBody
              || (hitgroup == SDK::HITGROUP_LEFTARM
                || hitgroup == SDK::HITGROUP_RIGHTARM
                || hitgroup == SDK::HITGROUP_LEFTLEG
                || hitgroup == SDK::HITGROUP_RIGHTLEG) && m_bTriggerLegsArms)
          {
            vector<Engine::CBaseEntity*> vTargets;
            if (m_bShotEnemies && !m_bShotFriendlies) vTargets = m_vEnemies;
            else if (!m_bShotEnemies && m_bShotFriendlies) vTargets = m_vFriendlies;
            else vTargets = m_vAllPlayers;

            for each (Engine::CBaseEntity* pEnemy in vTargets)
            {
              if (tr.m_pEnt == pEnemy)
              {
                float NextAttack = pWeapon->GetNextPrimaryAttack();

                if (G::pGlobals)
                {
                  float Tick = G::pMe->GetTickBase() * G::pGlobals->interval_per_tick;

                  if (NextAttack < Tick)
                  {
                    bool bIsEnemyVisible = pEnemy->IsVisible(G::pMe);
                    if (bIsEnemyVisible)
                    {
                      if (*pWeapon->GeteAttributableItem()->GetItemDefinitionIndex() == Engine::WEAPON_REVOLVER
                          //|| pWeapon->GetClientClass()->m_ClassID == (int)Engine::CLASS_ID::CKnifeGG)
                          || strstr(pWeapon->GetClientClass()->m_pNetworkName, XS("Knife")))
                      {
                        pCmd->buttons |= IN_ATTACK2;
                      }
                      else
                      {
                        pCmd->buttons |= IN_ATTACK;
                      }
                    }
                  }
                  else
                  {
                    if (*pWeapon->GeteAttributableItem()->GetItemDefinitionIndex() == Engine::WEAPON_REVOLVER
                        //|| pWeapon->GetClientClass()->m_ClassID == (int)Engine::CLASS_ID::CKnifeGG)
                        || strstr(pWeapon->GetClientClass()->m_pNetworkName, XS("Knife")))
                    {
                      pCmd->buttons &= ~IN_ATTACK2;
                    }
                    else
                    {
                      pCmd->buttons &= ~IN_ATTACK;
                    }
                  }

                  break;
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
    }
  }
}

void C_Triggerbot::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable triggerbot"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::Checkbox(XS("Autotrigger"), &m_bAutoTrigger);
    if (!m_bAutoTrigger)
    {
      string sItems[] = { XS("LAlt"), XS("LShift") };
      const char* items[] = { sItems[0].c_str(), sItems[1].c_str() };
      ImGui::Combo(XS("Trigger button"), &m_iKeyUse, items, IM_ARRAYSIZE(items));
    }
    ImGui::Checkbox(XS("Trigger Enemies"), &m_bShotEnemies);
    ImGui::Checkbox(XS("Trigger Friendlies"), &m_bShotFriendlies);
    ImGui::Checkbox(XS("Trigger head"), &m_bTriggerHead);
    ImGui::Checkbox(XS("Trigger body"), &m_bTriggerBody);
    ImGui::Checkbox(XS("Trigger legs & arms"), &m_bTriggerLegsArms);
  }
}

void C_Triggerbot::OnDraw()
{

}

bool C_Triggerbot::UndoChanges()
{
  return true;
}

bool C_Triggerbot::UndoDraws()
{
  return true;
}

