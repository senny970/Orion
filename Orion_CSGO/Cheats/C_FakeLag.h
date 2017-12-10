#pragma once

class C_FakeLag : public C_Cheat
{
public:
  C_FakeLag(const string &cheatName);
  virtual ~C_FakeLag();

  virtual void Perform(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();

  int m_iMaxLagTicks;

private:
  int m_iLaggedTickCount;
};

