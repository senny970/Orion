#pragma once

class C_Chams : public C_Cheat
{
public:
  C_Chams(const string &cheatName);
  virtual ~C_Chams();

  virtual void OnCreateMove(SDK::CUserCmd* pCmd);
  virtual bool UndoChanges();
  virtual bool UndoDraws();
  virtual void OnDrawMenu();
  virtual void OnDraw();

  void OnDrawModel(SDK::IVModelRender* thisptr, void* pEdx,
    SDK::IMatRenderContext* context, const SDK::DrawModelState_t &state,
    const SDK::ModelRenderInfo_t& info, SDK::matrix3x4_t* pCustomBoneToWorld);

  void ForceMaterial(SDK::IMaterial* material, SDK::Color color);

private:
  bool m_bFriendlies;
  bool m_bXQZ;
  int m_iMode;
};

