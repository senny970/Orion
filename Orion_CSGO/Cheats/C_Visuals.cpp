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

    int punch_x = (int)G::iScreenWidth / 2 + (int)vPunchAngle.y * -10;
    int punch_y = (int)G::iScreenHeight / 2 + (int)vPunchAngle.x * 10;

    G::pRender->DrawFillBox(punch_x - 1, punch_y - 1, 3, 3, SDK::Color::Green());
  }
}

bool C_Visuals::UndoChanges()
{
  return true;
}



