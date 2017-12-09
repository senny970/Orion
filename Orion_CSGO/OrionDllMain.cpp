#include "OrionIncludes.h"

int WINAPI DllMain(HINSTANCE hDllInstance, DWORD dwCallReason, LPVOID lpvReserved)
{
  if (dwCallReason == DLL_PROCESS_ATTACH)
  {
    //Disables DLL_THREAD_ATTACH && DLL_THREAD_DETACH
    //DisableThreadLibraryCalls(hInstanceDLL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)M::InitAll, hDllInstance, NULL, NULL);

    return 1;
  }
  else if (dwCallReason == DLL_PROCESS_DETACH)
  {
    return 1;
  }
  else if (dwCallReason == DLL_THREAD_ATTACH)
  {
    return 1;
  }
  else if (dwCallReason == DLL_THREAD_DETACH)
  {
    return 1;
  }
  return 0;
}