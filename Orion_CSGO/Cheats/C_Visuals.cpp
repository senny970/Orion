#include "../OrionIncludes.h"

C_Visuals::C_Visuals(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_bNoFlashEnabled = false;
  m_bDrawCrossHair = false;
  m_bDynamicCrosshair = false;
}

C_Visuals::~C_Visuals()
{

}

void C_Visuals::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bNoFlashEnabled)
  {
    *pMe->GetFlashDuration() = 0.0f;
  }
}

void C_Visuals::OnDrawMenu()
{
  ImGui::Checkbox(XS("No flash"), &m_bNoFlashEnabled);
  ImGui::Checkbox(XS("Draw crosshair"), &m_bDrawCrossHair);

  if (m_bDrawCrossHair)
  {
    ImGui::Checkbox(XS("Dynamic crosshair"), &m_bDynamicCrosshair);
  }
}

void C_Visuals::OnDraw()
{
  if (m_bDrawCrossHair)
  {
    SDK::Vector vPunchAngle(0.0f, 0.0f, 0.0f);

    if (m_bDynamicCrosshair)
    {
      if (pMe)
      {
        vPunchAngle = pMe->GetAimPunchAngle();
      }
    }

    int punch_x = (int)G::iScreenWidth / 2 + (int)vPunchAngle.y * -9;
    int punch_y = (int)G::iScreenHeight / 2 + (int)vPunchAngle.x * 9;

    G::pRender->DrawOutlineBox(punch_x - 2, punch_y, 5, 1, SDK::Color::Red());
    G::pRender->DrawOutlineBox(punch_x, punch_y - 2, 1, 5, SDK::Color::Red());
  }
}

bool C_Visuals::UndoChanges()
{
  return true;
}



