#pragma once

class C_Bhop : public C_Cheat
{
public:
  C_Bhop(const string &cheatName);
  virtual ~C_Bhop();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  bool m_bAutoStrafe;
};

