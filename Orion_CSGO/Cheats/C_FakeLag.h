#pragma once

class C_FakeLag : public C_Cheat
{
public:
  C_FakeLag(const string &cheatName);
  virtual ~C_FakeLag();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  int m_iLaggedTickCount;
  int m_iMaxLagTicks;
};

