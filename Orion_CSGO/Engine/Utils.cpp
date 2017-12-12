#include "../OrionIncludes.h"

bool Utils::CheckVisible(const SDK::Vector &vOrigin)
{
  Engine::CBaseEntity* pMe = (Engine::CBaseEntity*)G::pEntityList->GetClientEntity(G::pEngine->GetLocalPlayer());

  if (pMe)
  {
    SDK::trace_t tr;
    SDK::Ray_t ray;
    SDK::CTraceFilter Filter;
    Filter.pSkip = pMe;

    ray.Init(pMe->GetEyePosition(), vOrigin);

    G::pEngineTrace->TraceRay(ray, MASK_VISIBLE, &Filter, &tr);

    return tr.IsVisible();
  }

  return false;
}

void Utils::AngleVectors(const SDK::Vector &vAngles, SDK::Vector& vForward)
{
  float	sx, sy, cx, cy;

  sx = sin(DEG2RAD(vAngles.x));
  cx = cos(DEG2RAD(vAngles.x));

  sy = sin(DEG2RAD(vAngles.y));
  cy = cos(DEG2RAD(vAngles.y));

  vForward.x = cx*cy;
  vForward.y = cx*sy;
  vForward.z = -sx;
}

void Utils::VectorAngles(const SDK::Vector vForward, SDK::Vector& vAngle)
{
  float flTemp, yaw, pitch;

  if (vForward.y == 0 && vForward.x == 0)
  {
    yaw = 0;
    if (vForward.z > 0)
    {
      pitch = 270;
    }
    else
    {
      pitch = 90;
    }
  }
  else
  {
    yaw = (atan2(vForward.y, vForward.x) * 180 / M_PI);
    if (yaw < 0)
    {
      yaw += 360;
    }
    flTemp = sqrt(vForward.x * vForward.x + vForward.y * vForward.y);
    pitch = (atan2(-vForward.z, flTemp) * 180 / M_PI);

    if (pitch < 0)
    {
      pitch += 360;
    }
  }

  vAngle[0] = pitch;
  vAngle[1] = yaw;
  vAngle[2] = 0;
}

void Utils::AngleNormalize(SDK::Vector &vAngles)
{
  if (vAngles.x > 89.0f && vAngles.x <= 180.0f)
    vAngles.x = 89.0f;
  while (vAngles.x > 180.f)
    vAngles.x -= 360.f;
  while (vAngles.x < -89.0f)
    vAngles.x = -89.0f;
  while (vAngles.y > 180.f)
    vAngles.y -= 360.f;
  while (vAngles.y < -180.f)
    vAngles.y += 360.f;
  vAngles.z = 0;
}

void Utils::SmoothAngles(SDK::Vector MyViewAngles, SDK::Vector AimAngles,
  SDK::Vector &OutAngles, float Smoothing)
{
  OutAngles = AimAngles - MyViewAngles;

  AngleNormalize(OutAngles);

  OutAngles.x = OutAngles.x / Smoothing + MyViewAngles.x;
  OutAngles.y = OutAngles.y / Smoothing + MyViewAngles.y;

  AngleNormalize(OutAngles);
}

