#include "../OrionIncludes.h"

CM* CM::sm_pInstance = NULL;

CM* CM::Instance()
{
  if (!sm_pInstance)
  {
    sm_pInstance = new CM;
  }
  return sm_pInstance;
}

CM::CM()
{

}

CM::~CM()
{
  for (auto it = m_mapCheats.begin(); it != m_mapCheats.end(); it++)
  {
    it->second->Unload();
    delete it->second;
  }
  m_mapCheats.clear();
}

bool CM::RegCheat(C_Cheat* pCheat, const std::string &sCheatName)
{
  CM* pCheatMgr = Instance();

  if (pCheat == NULL)
    return false;
  if (sCheatName.empty())
    return false;

  auto iterator = pCheatMgr->m_mapCheats.find(sCheatName);
  if (iterator != pCheatMgr->m_mapCheats.end())
    return false;

  pCheatMgr->m_mapCheats.insert(
    std::pair<std::string, C_Cheat*>(sCheatName, pCheat));

  return true;
}

bool CM::UnregCheat(const std::string &sCheatName)
{
  CM* pCheatMgr = Instance();

  if (pCheatMgr->m_mapCheats.empty())
    return false;
  if (sCheatName.empty())
    return false;

  auto iterator = pCheatMgr->m_mapCheats.find(sCheatName);
  if (iterator == pCheatMgr->m_mapCheats.end())
    return false;

  iterator->second->Unload();
  delete iterator->second;
  pCheatMgr->m_mapCheats.erase(iterator);

  return true;
}

C_Cheat* CM::Get(const std::string &sCheatName)
{
  CM* pCheatMgr = Instance();

  if (pCheatMgr->m_mapCheats.empty())
    return NULL;
  if (sCheatName.empty())
    return NULL;

  auto iterator = pCheatMgr->m_mapCheats.find(sCheatName);
  if (iterator == pCheatMgr->m_mapCheats.end())
    return NULL;

  return iterator->second;
}

std::map<std::string, C_Cheat*> CM::GetCheats()
{
  CM* pCheatMgr = Instance();
  return pCheatMgr->m_mapCheats;
}

