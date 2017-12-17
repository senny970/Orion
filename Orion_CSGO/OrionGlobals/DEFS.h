#pragma once

#define MAX_PLAYERS 64

#ifndef M_PI
#define M_PI			3.14159265358979323846
#define DEG2RAD(x) ((float)x * (float)M_PI / 180.0f)
#define RAD2DEG(x) ((float)x * (float)180.0f / M_PI)
#endif

#define S_MS(ms) this_thread::sleep_for(chrono::milliseconds(ms));
#define S_MCS(mcs) this_thread::sleep_for(chrono::microseconds(mcs));
#define S_NS(ns) this_thread::sleep_for(chrono::nanoseconds(ns));

#define GVAR(TYPE, VAR, DEF) namespace G { extern __declspec(selectany) TYPE VAR = DEF; }
#define GET_CHEAT(CLASS, VAR) CLASS* VAR = (CLASS*)CM::Get(XS("" #CLASS));
#define REG_CHEAT(CH_CLASS) CM::RegCheat(new CH_CLASS(XS("" #CH_CLASS)), XS("" #CH_CLASS));

namespace SDK
{
  typedef Vector QAngle;
}

typedef HRESULT (__stdcall *IDirect3DDevice9_EndSceneFn)(IDirect3DDevice9* thisptr);

typedef HRESULT (__stdcall *IDirect3DDevice9_ResetFn)(
  IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* pPresentationParameters);

typedef bool (__stdcall *IClientMode_CreateMoveFn)(
  float flInputSampleTime, SDK::CUserCmd* pCmd);

typedef void (__stdcall *IBaseClientDll_CreateMoveFn)(
  int sequence_number, float input_sample_frametime, bool active);

typedef void(__stdcall *IBaseClientDll_FrameStageNotifyFn)(
  SDK::ClientFrameStage_t stage);

typedef void (__fastcall *IVModelRender_DrawModelExecuteFn)(
  SDK::IVModelRender* thisptr, void* pEdx, SDK::IMatRenderContext* context,
  const SDK::DrawModelState_t &state, const SDK::ModelRenderInfo_t& info,
  SDK::matrix3x4_t* pCustomBoneToWorld);


typedef void* (*CreateIFaceFn)(const char *pName, int *pReturnCode);

typedef bool (__cdecl *LineGoesThroughSmokeFn) (SDK::Vector, SDK::Vector);
typedef void (__thiscall *InitKeyValuesFn)(SDK::KeyValues* pKeyValues, const char* name);
typedef void (__thiscall *LoadFromBufferFn)(void* thisptr,
  const char* resourceName, const char* pBuffer, void* pFileSystem,
  const char* pPathID, void* pfnEvaluateSymbolProc);
