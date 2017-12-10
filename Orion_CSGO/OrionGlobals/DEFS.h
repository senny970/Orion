#pragma once

#define GVAR(TYPE, VAR, DEF) namespace G { extern TYPE VAR = DEF; }
#define GET_CHEAT(CLASS, VAR) CLASS* VAR = (CLASS*)CM::Get(XS("" #CLASS));
#define REG_CHEAT(CH_CLASS) CM::RegCheat(new CH_CLASS(XS("" #CH_CLASS)), XS("" #CH_CLASS));

typedef HRESULT (__stdcall *IDirect3DDevice9_EndSceneFn)(IDirect3DDevice9* thisptr);

typedef HRESULT (__stdcall *IDirect3DDevice9_ResetFn)(
  IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* pPresentationParameters);

typedef bool (__stdcall *IClientMode_CreateMoveFn)(
  float flInputSampleTime, SDK::CUserCmd* pCmd);

typedef void (__stdcall *IBaseClientDll_CreateMoveFn)(
  int sequence_number, float input_sample_frametime, bool active);

typedef void* (*CreateIFaceFn)(const char *pName, int *pReturnCode);
