#include "OrionIncludes.h"

int WINAPI DllMain(HINSTANCE hDllInstance, DWORD dwCallReason, LPVOID lpvReserved)
{
  if (dwCallReason == DLL_PROCESS_ATTACH)
  {
    //Disables DLL_THREAD_ATTACH && DLL_THREAD_DETACH
    //DisableThreadLibraryCalls(hInstanceDLL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)M::InitAll, hDllInstance, NULL, NULL);
    cout << "Process attached: " << hex << hDllInstance << dec << endl;

    return 1;
  }
  else if (dwCallReason == DLL_PROCESS_DETACH)
  {
    cout << "Process detached: " << hex << hDllInstance << dec << endl;
    return 1;
  }
  else if (dwCallReason == DLL_THREAD_ATTACH)
  {
    cout << "Thread attached: " << hex << hDllInstance << dec << endl;
    return 1;
  }
  else if (dwCallReason == DLL_THREAD_DETACH)
  {
    cout << "Thread detached: " << hex << hDllInstance << dec << endl;
    return 1;
  }
  return 0;
}