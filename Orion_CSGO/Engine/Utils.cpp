#include "../OrionIncludes.h"

void Utils::AngleVectors(const SDK::Vector &vAngles, SDK::Vector& vForward)
{
  float	sx, sy, cx, cy;

  sx = sin(DEG2RAD(vAngles.x));
  
  sy = sin(DEG2RAD(vAngles.y));
  
  cx = cos(DEG2RAD(vAngles.x));
  
  cy = cos(DEG2RAD(vAngles.y));
  
  vForward.x = cx*cy;
  
  vForward.y = cx*sy;
  
  vForward.z = -sx;
}

//void Utils::VectorAngles(const SDK::Vector vForward, SDK::Vector& vAngle)
//{
//  float flTemp, yaw, pitch;
//
//  if (vForward.x == 0 && vForward.y == 0)
//  {
//    if (vForward.z <= 0)
//    {
//      pitch = 90;
//    }
//    else
//    {
//      pitch = 270;
//    }
//    yaw = 0;
//  }
//  else
//  {
//    flTemp = sqrt(vForward.x * vForward.x + vForward.y * vForward.y);
//    pitch = ((float)RAD2DEG(atan2(-vForward.z, flTemp)));
//
//    if (pitch < 0)
//    {
//      pitch += 180;
//      pitch += 180;
//    }
//
//    yaw = ((float)RAD2DEG(atan2(vForward.y, vForward.x)));
//    if (yaw < 0)
//    {
//      yaw += 180;
//      yaw += 180;
//    }
//  }
//
//  vAngle[0] = pitch;
//  vAngle[1] = yaw;
//  vAngle[2] = 0;
//}

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

//void Utils::SmoothAngles(SDK::Vector MyViewAngles, SDK::Vector AimAngles,
//  SDK::Vector &OutAngles, float Smoothing)
//{
//  if (Smoothing <= 0.0f) Smoothing = 1.0f;
//
//  OutAngles = AimAngles - MyViewAngles;
//
//  AngleNormalize(OutAngles);
//
//  OutAngles.x = OutAngles.x / Smoothing + MyViewAngles.x;
//  OutAngles.y = OutAngles.y / Smoothing + MyViewAngles.y;
//
//  AngleNormalize(OutAngles);
//}

//SDK::Vector Utils::CalcAng(SDK::Vector vOrigin, SDK::Vector vEnd)
//{
//  SDK::QAngle angles;
//  SDK::Vector delta = vEnd - vOrigin;
//
//  VectorAngles(delta, angles);
//
//  Utils::AngleNormalize(angles);
//
//  return angles;
//}

SDK::IMaterial* Utils::CreateMaterial(bool flat, bool ignorez, bool wireframed)
{
  static int iCreated = 0;
  std::string matname = XS("orion_model_") + std::to_string(iCreated++) + XS(".vmt");

  SDK::KeyValues* pKeyValues = new SDK::KeyValues(matname.c_str());

  std::string sMatType;
  if (!flat)
  {
    sMatType = XS("VertexLitGeneric");
  }
  else
  {
    sMatType = XS("UnlitGeneric");
  }

  G::InitKeyValues(pKeyValues, sMatType.c_str());

  std::string sMatData = XS("\"") + sMatType + XS("\"\n");
  sMatData += XS("{\n");
  sMatData += XS("\t\"$basetexture\" \"vgui/white_additive\"\n");
  sMatData += XS("\t\"$flat\" \"1\"\n");
  sMatData += XS("\t\"$halflambert\" \"1\"\n");
  sMatData += XS("\t\"$ignorez\" \"") + std::to_string(ignorez) + XS("\"\n");
  sMatData += XS("\t\"$nocull\" \"0\"\n");
  sMatData += XS("\t\"$znearer\" \"0\"\n");
  sMatData += XS("\t\"$wireframe\" \"") + std::to_string(wireframed) + XS("\"\n");
  sMatData += XS("\t\"$nofog\" \"0\"\n");
  sMatData += XS("\t\"$envmap\" \"\"\n");
  sMatData += XS("\t\"$model\" \"1\"\n");
  sMatData += XS("\t\"$selfillum\" \"1\"\n");
  sMatData += XS("}\n");

  G::LoadFromBuffer(pKeyValues, matname.c_str(), sMatData.c_str(), 0, 0, 0);

  SDK::IMaterial* pCreatedMaterial = nullptr;
  if (G::pMaterialSystem)
  {
    pCreatedMaterial = G::pMaterialSystem->CreateMaterial(matname.c_str(), pKeyValues);
    pCreatedMaterial->IncrementReferenceCount();
  }
  return pCreatedMaterial;
}

