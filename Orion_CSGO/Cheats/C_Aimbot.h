#pragma once

class C_Aimbot : public C_Cheat
{
public:
  C_Aimbot(const string &cheatName);
  virtual ~C_Aimbot();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:

};

