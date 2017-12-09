#include "../OrionIncludes.h"

C_CheatMgr* C_CheatMgr::sm_pInstance = NULL;

C_CheatMgr* C_CheatMgr::Instance()
{
  if (!sm_pInstance)
  {
    sm_pInstance = new C_CheatMgr;
  }
  return sm_pInstance;
}

C_CheatMgr::C_CheatMgr()
{

}

C_CheatMgr::~C_CheatMgr()
{
  for (auto it = m_mapCheats.begin(); it != m_mapCheats.end(); it++)
  {
    delete it->second;
  }
  m_mapCheats.clear();
}

bool C_CheatMgr::RegCheat(C_Cheat* pCheat, const std::string &sCheatName)
{
  C_CheatMgr* pCheatMgr = Instance();

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

bool C_CheatMgr::UnregCheat(const std::string &sCheatName)
{
  C_CheatMgr* pCheatMgr = Instance();

  if (pCheatMgr->m_mapCheats.empty())
    return false;
  if (sCheatName.empty())
    return false;

  auto iterator = pCheatMgr->m_mapCheats.find(sCheatName);
  if (iterator == pCheatMgr->m_mapCheats.end())
    return false;

  delete iterator->second;
  pCheatMgr->m_mapCheats.erase(iterator);

  return true;
}

C_Cheat* C_CheatMgr::GetCheat(const std::string &sCheatName)
{
  C_CheatMgr* pCheatMgr = Instance();

  if (pCheatMgr->m_mapCheats.empty())
    return NULL;
  if (sCheatName.empty())
    return NULL;

  auto iterator = pCheatMgr->m_mapCheats.find(sCheatName);
  if (iterator == pCheatMgr->m_mapCheats.end())
    return NULL;

  return iterator->second;
}

std::map<std::string, C_Cheat*> C_CheatMgr::GetCheats()
{
  C_CheatMgr* pCheatMgr = Instance();
  return pCheatMgr->m_mapCheats;
}

