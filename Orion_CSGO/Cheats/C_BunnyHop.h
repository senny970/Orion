#pragma once

class C_BunnyHop : public C_Cheat
{
public:
  C_BunnyHop(const string &cheatName);
  virtual ~C_BunnyHop();

  virtual void Perform(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();

  bool m_bAutoStrafe;
};

