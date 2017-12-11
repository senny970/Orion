#include "../OrionIncludes.h"

C_FakeLag::C_FakeLag(const string& sCheatName)
  : C_Cheat(sCheatName)
{
  m_iLaggedTickCount = 0;
  m_iMaxLagTicks = 1;
}

C_FakeLag::~C_FakeLag()
{
  
}

void C_FakeLag::OnCreateMove(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (m_iLaggedTickCount < m_iMaxLagTicks)
    {
      G::bSendPacket = false;
      m_iLaggedTickCount++;
    }
    else
    {
      G::bSendPacket = true;
      m_iLaggedTickCount = 0;
    }
  }
  else
  {
    if (m_iLaggedTickCount > 0)
    {
      G::bSendPacket = true;
      m_iLaggedTickCount = 0;
    }
  }
}

bool C_FakeLag::OnDraw()
{
  ImGui::Checkbox(XS("Enable fakelag"), &m_bEnabled);
  if (m_bEnabled)
  {
    ImGui::SliderInt(XS("Fakelag value"), &m_iMaxLagTicks, 1, 5);
  }
  return true;
}

bool C_FakeLag::UndoChanges()
{
  G::bSendPacket = true;
  return G::bSendPacket;
}



