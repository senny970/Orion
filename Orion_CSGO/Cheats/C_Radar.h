#pragma once

class C_Radar : public C_Cheat
{
public:
  C_Radar(const string &cheatName);
  virtual ~C_Radar();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:

};

