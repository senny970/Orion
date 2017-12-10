#include "../OrionIncludes.h"

C_Cheat::C_Cheat(const string &sCheatName)
  : m_sName(sCheatName),
    m_bEnabled(false)
{
  pMe = (E::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());
}

C_Cheat::~C_Cheat()
{
  m_bEnabled = false;
}

bool C_Cheat::Unload()
{
  return UndoChanges();
}
