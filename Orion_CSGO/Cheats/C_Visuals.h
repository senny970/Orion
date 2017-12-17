#pragma once

class C_Visuals : public C_Cheat
{
public:
  C_Visuals(const string &cheatName);
  virtual ~C_Visuals();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

  void OnFrameStageNotify(SDK::ClientFrameStage_t stage);
  void AfterFrameStageNotify(SDK::ClientFrameStage_t stage);

  //bool m_bNoRecoil;
private:
  bool m_bNoFlashEnabled;
  bool m_bDrawCrossHair;
  bool m_bDynamicCrosshair;

  int m_iCrosshairSize;

  //SDK::Vector vAimPunchOld;
  //SDK::Vector vViewPunchOld;

  //SDK::Vector* pvAimPunch;
  //SDK::Vector* pvViewPunch;
};

