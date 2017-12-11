#pragma once

class C_Visuals : public C_Cheat
{
public:
  C_Visuals(const string &cheatName);
  virtual ~C_Visuals();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual void OnDrawMenu();
  virtual void OnDraw();

private:
  bool m_bNoFlashEnabled;
  bool m_bDrawCrossHair;
  bool m_bDynamicCrosshair;
};

