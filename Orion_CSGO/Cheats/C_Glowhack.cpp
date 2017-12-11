#include "../OrionIncludes.h"

C_Glowhack::C_Glowhack(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bDrawedOnce = false;
  m_bDrawC4 = false;
  m_bDrawEnemies = false;
  m_bDrawFriendlies = false;
  m_bDrawGranades = false;
  m_bDrawWeapons = false;
}

C_Glowhack::~C_Glowhack()
{

}

void C_Glowhack::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (!G::pEngine->IsTakingScreenshot())
    {
      SDK::CGlowObjectManager* pGlowManager = (SDK::CGlowObjectManager*)Engine::Offset::GlowManager;

      for (int i = 0; i < pGlowManager->size; i++)
      {
        SDK::CGlowObjectManager::GlowObjectDefinition_t* pGlowObject = &pGlowManager->m_GlowObjectDefinitions[i];
        Engine::CBaseEntity* pTargetEntity = pGlowObject->GetEntity();

        if (pGlowObject->IsEmpty() || !pTargetEntity)
        {
          continue;
        }

        switch ((Engine::CLASS_ID)pTargetEntity->GetClientClass()->m_ClassID)
        {
          case Engine::CLASS_ID::CPlantedC4:
          {
            if (m_bDrawC4)
            {
              pGlowObject->Set(SDK::Color(84, 0, 100, 250));
              m_bDrawedOnce = true;
              break;
            }
            break;
          }
          case Engine::CLASS_ID::CC4:
          {
            if (m_bDrawC4)
            {
              pGlowObject->Set(SDK::Color(84, 147, 230, 250));
              m_bDrawedOnce = true;
              break;
            }
            break;
          }
          case Engine::CLASS_ID::CCSPlayer:
          {
            if (m_bDrawEnemies)
            {
              if (pTargetEntity->GetTeam() != pMe->GetTeam())
              {
                if (pTargetEntity->IsVisible(pMe))
                {
                  pGlowObject->Set(SDK::Color(200, 60, 60, 250));
                  m_bDrawedOnce = true;
                  break;
                }
                else
                {
                  pGlowObject->Set(SDK::Color(232, 209, 100, 250));
                  m_bDrawedOnce = true;
                  break;
                }
              }
            }
            if (m_bDrawFriendlies)
            {
              if (pTargetEntity->GetTeam() == pMe->GetTeam())
              {
                if (pTargetEntity->IsVisible(pMe))
                {
                  pGlowObject->Set(SDK::Color(72, 219, 75, 250));
                  m_bDrawedOnce = true;
                  break;
                }
                else
                {
                  pGlowObject->Set(SDK::Color(100, 200, 255, 250));
                  m_bDrawedOnce = true;
                  break;
                }
              }
            }
            break;
          }
          default:
          {
            if (m_bDrawGranades)
            {
              if (strstr(pTargetEntity->GetClientClass()->m_pNetworkName, XS("Projectile"))
                  || strstr(pTargetEntity->GetClientClass()->m_pNetworkName, XS("Grenade")))
              {
                pGlowObject->Set(SDK::Color(230, 78, 255, 250));
                m_bDrawedOnce = true;
                break;
              }
            }
            if (m_bDrawWeapons)
            {
              if (strstr(pTargetEntity->GetClientClass()->m_pNetworkName, XS("Weapon"))
                  || strstr(pTargetEntity->GetClientClass()->m_pNetworkName, XS("AK47")))
              {
                pGlowObject->Set(SDK::Color(255, 138, 46, 250));
                m_bDrawedOnce = true;
                break;
              }
            }
            break;
          }
        }
      }
    }
  }
  else
  {
    if (m_bDrawedOnce)
    {
      UndoChanges();
      m_bDrawedOnce = false;
    }
  }
}

void C_Glowhack::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable glowhack"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::Checkbox(XS("Draw enemies"), &m_bDrawEnemies);
    ImGui::Checkbox(XS("Draw friendlies"), &m_bDrawFriendlies);
    ImGui::Checkbox(XS("Draw C4"), &m_bDrawC4);
    ImGui::Checkbox(XS("Draw weapons"), &m_bDrawWeapons);
    ImGui::Checkbox(XS("Draw granades"), &m_bDrawGranades);
  }
}

void C_Glowhack::OnDraw()
{

}

bool C_Glowhack::UndoChanges()
{
  if (!G::pEngine->IsTakingScreenshot())
  {
    SDK::CGlowObjectManager* pGlowManager = (SDK::CGlowObjectManager*)Engine::Offset::GlowManager;

    for (int i = 0; i < pGlowManager->size; i++)
    {
      SDK::CGlowObjectManager::GlowObjectDefinition_t* pGlowObject = &pGlowManager->m_GlowObjectDefinitions[i];
      Engine::CBaseEntity* pTargetEntity = pGlowObject->GetEntity();

      if (pGlowObject->IsEmpty() || !pTargetEntity)
      {
        continue;
      }

      pGlowObject->Set(SDK::Color(0, 0, 0, 0));
    }
  }
  return true;
}



