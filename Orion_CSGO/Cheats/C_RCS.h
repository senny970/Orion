#pragma once

class C_RCS : public C_Cheat
{
public:
  C_RCS(const string &cheatName);
  virtual ~C_RCS();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  SDK::Vector m_vOldPunch;
};

