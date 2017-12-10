#pragma once

class C_Cheat
{
public:
	C_Cheat(const string &cheatName);
	virtual ~C_Cheat();

	virtual void Perform(SDK::CUserCmd* pCmd) = 0;
  virtual bool UndoChanges() = 0;

  virtual bool Unload();

  bool m_bEnabled;
  string m_sName;

protected:
  E::CBaseEntity* pMe;
};

