#pragma once

class C_CheatMgr
{
public:
  ~C_CheatMgr();

  static C_CheatMgr* Instance();

  static bool RegCheat(C_Cheat* pCheat, const std::string &sCheatName);
  static bool UnregCheat(const std::string &sCheatName);

  static C_Cheat* GetCheat(const std::string &sCheatName);
  static std::map<std::string, C_Cheat*> GetCheats();

private:
  C_CheatMgr();

  static C_CheatMgr* sm_pInstance;

  std::map<std::string, C_Cheat*> m_mapCheats;
};