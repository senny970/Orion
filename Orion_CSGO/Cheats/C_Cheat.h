#pragma once

class C_Cheat
{
public:
	C_Cheat(const string &cheatName);
	virtual ~C_Cheat();

	virtual void OnCreateMove(SDK::CUserCmd* pCmd) = 0;
  virtual bool UndoChanges() = 0;
  virtual bool OnDraw() = 0;

  virtual bool Unload();

protected:
  E::CBaseEntity* pMe;
  bool m_bEnabled;
  string m_sName;
};

