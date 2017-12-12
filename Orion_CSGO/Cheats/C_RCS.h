#pragma once

class C_RCS : public C_Cheat
{
public:
  C_RCS(const string &cheatName);
  virtual ~C_RCS();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  SDK::QAngle m_vOldAngle;
};

