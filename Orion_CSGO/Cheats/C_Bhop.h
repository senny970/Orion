#pragma once

class C_Bhop : public C_Cheat
{
public:
  C_Bhop(const string &cheatName);
  virtual ~C_Bhop();

  virtual void Perform(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();

  bool m_bAutoStrafe;
};

