#pragma once

class C_Triggerbot : public C_Cheat
{
public:
  C_Triggerbot(const string &cheatName);
  virtual ~C_Triggerbot();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:

};

