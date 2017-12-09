#include "../OrionIncludes.h"

C_Cheat::C_Cheat(const string &sCheatName)
  : m_sName(sCheatName),
    m_bInitialized(false),
    m_bEnabled(false)
{
  pLocalPlayer = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());
}

C_Cheat::~C_Cheat()
{
  Unload();
}

bool C_Cheat::Unload()
{
  m_bEnabled = false;
  m_bInitialized = false;

  return UndoChanges();
}


