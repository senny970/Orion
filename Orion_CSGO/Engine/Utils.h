#pragma once

namespace Utils
{
  bool CheckVisible(const SDK::Vector &vOrigin);

  void AngleVectors(const SDK::Vector &vAngles, SDK::Vector& vForward);
  void VectorAngles(const SDK::Vector vForward, SDK::Vector& vAngle);

  void AngleNormalize(SDK::Vector &vAngles);

  void SmoothAngles(SDK::Vector MyViewAngles, SDK::Vector AimAngles,
    SDK::Vector &OutAngles, float Smoothing);

}





