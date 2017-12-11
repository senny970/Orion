#include "../OrionIncludes.h"

C_Glowhack::C_Glowhack(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bDrawC4 = false;
  m_bDrawEnemies = false;
  m_bDrawFriendlies = false;
  m_bDrawDecoys = false;
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
          case Engine::CLASS_ID::CC4:
          {
            if (m_bDrawC4)
            {
              pGlowObject->Set(SDK::Color(84, 147, 230, 250));
              break;
            }
            break;
          }
          case Engine::CLASS_ID::CPlantedC4:
          {
            if (m_bDrawC4)
            {
              pGlowObject->Set(SDK::Color(84, 0, 100, 250));
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
                  break;
                }
                else
                {
                  pGlowObject->Set(SDK::Color(232, 209, 32, 250));
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
                  break;
                }
                else
                {
                  pGlowObject->Set(SDK::Color(84, 167, 255, 250));
                  break;
                }
              }
            }
            break;
          }
          case Engine::CLASS_ID::CDecoyProjectile:
          {
            if (m_bDrawDecoys)
            {
              pGlowObject->Set(SDK::Color(230, 78, 255, 250));
              break;
            }
            break;
          }
          case Engine::CLASS_ID::CPhysicsPropMultiplayer:
          {
            if (true)
            {
              pGlowObject->Set(SDK::Color(255, 39, 33, 250));
            }
            break;
          }
          default:
          {
            if (m_bDrawWeapons)
            {
              if (strstr(pTargetEntity->GetClientClass()->m_pNetworkName, XS("Weapon")))
              {
                pGlowObject->Set(SDK::Color(255, 138, 46, 250));
                break;
              }
            }
            break;
          }
        }
      }
    }
  }
}

bool C_Glowhack::OnDraw()
{
  ImGui::Checkbox(XS("Enable glowhack"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::Checkbox(XS("Draw C4"), &m_bDrawC4);
    ImGui::Checkbox(XS("Draw enemies"), &m_bDrawEnemies);
    ImGui::Checkbox(XS("Draw friendlies"), &m_bDrawFriendlies);
    ImGui::Checkbox(XS("Draw decoys"), &m_bDrawDecoys);
    ImGui::Checkbox(XS("Draw weapons"), &m_bDrawWeapons);
  }
  return true;
}

bool C_Glowhack::UndoChanges()
{
  return true;
}



