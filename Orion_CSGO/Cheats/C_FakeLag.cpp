#include "../OrionIncludes.h"

C_FakeLag::C_FakeLag(const string& sCheatName)
  : C_Cheat(sCheatName),
    m_iLaggedTickCount(0),
    m_iMaxLagTicks(1)
{

}

C_FakeLag::~C_FakeLag()
{
  
}

void C_FakeLag::Perform(SDK::CUserCmd* pCmd)
{
  if (m_bEnabled)
  {
    if (m_iLaggedTickCount < m_iMaxLagTicks)
    {
      U::PatchMgr::ApplyPatch(XS("pSendPacket"));
      m_iLaggedTickCount++;
    }
    else
    {
      U::PatchMgr::RestorePatch(XS("pSendPacket"));
      m_iLaggedTickCount = 0;
    }
  }
}

bool C_FakeLag::UndoChanges()
{
  return true;
}



