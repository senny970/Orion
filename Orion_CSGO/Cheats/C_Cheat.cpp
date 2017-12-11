#include "../OrionIncludes.h"

C_Cheat::C_Cheat(const string &sCheatName)
{
  m_sName = sCheatName;
  m_bEnabled = false;

  pMe = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());
}

C_Cheat::~C_Cheat()
{
  m_bEnabled = false;
}

void C_Cheat::UpdateEntities()
{
  m_vAllPlayers.clear();
  m_vEnemies.clear();
  m_vFriendlies.clear();

  pMe = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());

  if (pMe)
  {
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
      Engine::CBaseEntity* pEntity = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(i);

      if (pEntity && pEntity->IsPlayer() && pEntity->IsAlive()
          && pEntity->GetClientClass()->m_ClassID == (int)Engine::CLASS_ID::CCSPlayer
        )
      {
        m_vAllPlayers.push_back(pEntity);

        if (pMe && pEntity != pMe && i != G::pEngine->GetLocalPlayer())
        {
          if (pEntity->GetTeam() == pMe->GetTeam())
          {
            m_vFriendlies.push_back(pEntity);
          }
          else
          {
            m_vEnemies.push_back(pEntity);
          }
        }
      }
    }
  }
}

bool C_Cheat::Unload()
{
  return UndoChanges();
}
