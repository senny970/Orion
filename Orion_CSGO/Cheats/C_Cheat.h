#pragma once

class C_Cheat
{
public:
	C_Cheat(const string &cheatName);
	virtual ~C_Cheat();

	virtual void OnCreateMove(SDK::CUserCmd* pCmd) = 0;
  virtual bool UndoChanges() = 0;

  virtual void OnDrawMenu() = 0;
  virtual void OnDraw() = 0;

  virtual void UpdateEntities();
  virtual bool Unload();

protected:
  Engine::CBaseEntity* pMe;
  bool m_bEnabled;
  string m_sName;

  vector<Engine::CBaseEntity*> m_vAllPlayers;
  vector<Engine::CBaseEntity*> m_vEnemies;
  vector<Engine::CBaseEntity*> m_vFriendlies;
};

