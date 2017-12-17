#pragma once

namespace Utils
{
  void AngleVectors(const SDK::Vector &vAngles, SDK::Vector& vForward);
  //void VectorAngles(const SDK::Vector vForward, SDK::Vector& vAngle);

  void AngleNormalize(SDK::Vector &vAngles);

  //void SmoothAngles(SDK::Vector MyViewAngles, SDK::Vector AimAngles,
  //  SDK::Vector &OutAngles, float Smoothing);

  //SDK::Vector CalcAng(SDK::Vector vOrigin, SDK::Vector vEnd);

  SDK::IMaterial* CreateMaterial(bool flat, bool ignorez, bool wireframed);
}





