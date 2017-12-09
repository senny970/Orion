#pragma once

#define GVAR(TYPE, VAR, DEF) namespace G { extern TYPE VAR = DEF; }

typedef HRESULT (__stdcall *IDirect3DDevice9_EndSceneFn)(IDirect3DDevice9* thisptr);

typedef HRESULT (__stdcall *IDirect3DDevice9_ResetFn)(
  IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* pPresentationParameters);

typedef bool (__stdcall *IClientMode_CreateMoveFn)(
  float flInputSampleTime, SDK::CUserCmd* pCmd);

typedef void* (*CreateIFaceFn)(const char *pName, int *pReturnCode);