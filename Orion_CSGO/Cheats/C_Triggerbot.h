#pragma once

class C_Triggerbot : public C_Cheat
{
public:
  C_Triggerbot(const string &cheatName);
  virtual ~C_Triggerbot();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  bool m_bAutoTrigger;
  bool m_bShotEnemies;
  bool m_bShotFriendlies;
  bool m_bTriggerHead;
  bool m_bTriggerBody;
  bool m_bTriggerLegsArms;

  int m_iKeyUse;
};

