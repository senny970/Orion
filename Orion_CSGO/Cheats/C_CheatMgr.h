#pragma once

class CM
{
public:
  ~CM();

  static CM* Instance();

  static bool RegCheat(C_Cheat* pCheat, const std::string &sCheatName);
  static bool UnregCheat(const std::string &sCheatName);

  static C_Cheat* Get(const std::string &sCheatName);
  static std::map<std::string, C_Cheat*> GetCheats();

private:
  CM();

  static CM* sm_pInstance;

  std::map<std::string, C_Cheat*> m_mapCheats;
};