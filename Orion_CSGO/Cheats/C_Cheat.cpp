#include "../OrionIncludes.h"

C_Cheat::C_Cheat(const string &sCheatName)
{
  m_sName = sCheatName;
  m_bEnabled = false;
}

C_Cheat::~C_Cheat()
{
  m_bEnabled = false;
}

bool& C_Cheat::IsEnabled()
{
  return m_bEnabled;
}

void C_Cheat::UpdateEntities()
{
  m_vAllPlayers.clear();
  m_vEnemies.clear();
  m_vFriendlies.clear();

  if (G::pMe)
  {
    for (int i = 0; i < G::pEntityList->GetHighestEntityIndex(); i++)
    {
      Engine::CBaseEntity* pEntity = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(i);

      if (pEntity && pEntity->IsPlayer() && pEntity->IsAlive()
          && pEntity->GetClientClass()->m_ClassID == (int)Engine::CLASS_ID::CCSPlayer
        )
      {
        m_vAllPlayers.push_back(pEntity);

        if (G::pMe && pEntity != G::pMe && i != G::pEngine->GetLocalPlayer())
        {
          if (pEntity->GetTeam() == G::pMe->GetTeam())
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
  return (UndoDraws() & UndoChanges());
}
