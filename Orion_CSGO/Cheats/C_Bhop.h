#pragma once

class C_Bhop : public C_Cheat
{
public:
  C_Bhop(const string &cheatName);
  virtual ~C_Bhop();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool OnDraw();

private:
  bool m_bAutoStrafe;
};

