//#include "../OrionIncludes.h"
//
//C_Aimbot::C_Aimbot(const string& sCheatName)
//  : C_Cheat(sCheatName)
//{
//  m_flSmooth = 20.0f;
//}
//
//C_Aimbot::~C_Aimbot()
//{
//
//}
//
//void C_Aimbot::OnCreateMove(SDK::CUserCmd* pCmd)
//{
//  if (m_bEnabled)
//  {
//    if (GetAsyncKeyState(VK_RBUTTON))
//    //if (pCmd->buttons & IN_ATTACK)
//    {
//      if (!m_vEnemies.empty())
//      {
//        SDK::Vector vAimAngs = Utils::CalcAng(pMe->GetEyePosition(), m_vEnemies[0]->GetHitboxPosition(SDK::HITBOX_HEAD));
//        vAimAngs -= *pMe->GetAimPunchAngle() * 2;
//        Utils::SmoothAngles(pCmd->viewangles, vAimAngs, vAimAngs, m_flSmooth);
//        pCmd->viewangles = vAimAngs;
//      }
//    }
//  }
//}
//
//void C_Aimbot::OnDrawMenu()
//{
//  ImGui::Checkbox(XS("Enable aimbot"), &m_bEnabled);
//  if (m_bEnabled)
//  {
//    ImGui::SliderFloat(XS("Aimbot Smooth"), &m_flSmooth, 0.0f, 100.0f, XS("%0.1f"));
//  }
//}
//
//void C_Aimbot::OnDraw()
//{
//
//}
//
//bool C_Aimbot::UndoChanges()
//{
//  return true;
//}
//
//bool C_Aimbot::UndoDraws()
//{
//  return true;
//}
//
