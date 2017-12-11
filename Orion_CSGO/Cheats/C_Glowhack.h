#pragma once

class C_Glowhack : public C_Cheat
{
public:
  C_Glowhack(const string &cheatName);
  virtual ~C_Glowhack();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool OnDraw();

private:
  bool m_bDrawC4;
  bool m_bDrawEnemies;
  bool m_bDrawFriendlies;
  bool m_bDrawDecoys;
  bool m_bDrawWeapons;
};

