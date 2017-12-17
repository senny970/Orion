#include "../OrionIncludes.h"

C_Chams::C_Chams(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bFriendlies = false;
  m_bXQZ = false;
  m_iMode = 0;
}

C_Chams::~C_Chams()
{

}

void C_Chams::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {

  }
}

void C_Chams::OnDrawMenu()
{
  ImGui::Checkbox(XS("Enable chams"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::Checkbox(XS("Highlight friendlies"), &m_bFriendlies);
    string sItems[] = { XS("Flat"), XS("Texture") };
    const char* items[] = { sItems[0].c_str(), sItems[1].c_str() };
    ImGui::Combo(XS("Chams mode"), &m_iMode, items, IM_ARRAYSIZE(items));
    ImGui::Checkbox(XS("XQZ"), &m_bXQZ);
  }
}

void C_Chams::OnDraw()
{

}

void C_Chams::OnDrawModel(SDK::IVModelRender* thisptr, void* pEdx,
  SDK::IMatRenderContext* context, const SDK::DrawModelState_t &state,
  const SDK::ModelRenderInfo_t& info, SDK::matrix3x4_t* pCustomBoneToWorld)
{
  if (m_bEnabled)
  {
    if (G::pEngine /*&& G::pEngine->IsConnected()*/)
    {
      if (G::pModelInfo)
      {
        std::string sModelName = G::pModelInfo->GetModelName(info.pModel);

        if (sModelName.empty())
        {
          return;
        }

        if (sModelName.find(XS("models/player")) != std::string::npos)
        {
          if (G::pEntityList)
          {
            Engine::CBaseEntity* pModelEntity = (Engine::CBaseEntity*)G::pEntityList->
              GetClientEntity(info.entity_index);

            if (G::pMe && G::pMe->IsPlayer() && G::pMe->IsAlive())
            {
              if (pModelEntity && pModelEntity->IsPlayer() && pModelEntity->IsAlive())
              {
                SDK::Color colorHidden = SDK::Color(255, 255, 0, 255);
                SDK::Color colorVisible = SDK::Color(255, 0, 0, 255);

                if (pModelEntity->GetTeam() == G::pMe->GetTeam())
                {
                  if (!m_bFriendlies) return;
                  colorHidden = SDK::Color(0, 255, 255, 255);
                  colorVisible = SDK::Color(0, 255, 0, 255);
                }

                if (m_bXQZ)
                {
                  if (G::pHiddenFlat && G::pHiddenTexture)
                  {
                    SDK::IMaterial* pMat = nullptr;
                    if (m_iMode == 0)
                    {
                      pMat = G::pHiddenFlat;
                    }
                    else if (m_iMode == 1)
                    {
                      pMat = G::pHiddenTexture;
                    }
                    if (pMat)
                    {
                      ForceMaterial(pMat, colorHidden);
                      U::VMTHookMgr::GetHook(XS("IVModelRender_DrawModelExecute"))->
                        GetOriginFn<IVModelRender_DrawModelExecuteFn>()(
                          thisptr, pEdx, context, state, info, pCustomBoneToWorld);
                    }
                  }
                }

                if (G::pVisibleFlat && G::pVisibleTexture)
                {
                  SDK::IMaterial* pMat = nullptr;
                  if (m_iMode == 0)
                  {
                    pMat = G::pVisibleFlat;
                  }
                  else if (m_iMode == 1)
                  {
                    pMat = G::pVisibleTexture;
                  }
                  if (pMat)
                  {
                    ForceMaterial(pMat, colorVisible);
                    U::VMTHookMgr::GetHook(XS("IVModelRender_DrawModelExecute"))->
                      GetOriginFn<IVModelRender_DrawModelExecuteFn>()(
                        thisptr, pEdx, context, state, info, pCustomBoneToWorld);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void C_Chams::ForceMaterial(SDK::IMaterial* pMaterial, SDK::Color color)
{
  if (pMaterial)
  {
    if (G::pRenderView)
    {
      float alpha = (float)color.a() / 255.f;
      float r = color.r() / 255.0f;
      float g = color.g() / 255.0f;
      float b = color.b() / 255.0f;
      float flBase[3] =
      {
        r,
        g,
        b
      };

      G::pRenderView->SetColorModulation(flBase);
      G::pRenderView->SetBlend(alpha);
      if (G::pModelRender)
      {
        G::pModelRender->ForcedMaterialOverride(pMaterial);
      }
    }
  }
}

bool C_Chams::UndoChanges()
{
  return true;
}

bool C_Chams::UndoDraws()
{
  return true;
}



