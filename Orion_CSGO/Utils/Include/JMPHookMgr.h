#pragma once

#include <map>

namespace U
{
  class JMPHookMgr
  {
  public:
    ~JMPHookMgr();

    static JMPHookMgr* Instance();

    static bool RegHook(
      void* pJumpStart,
      int iInstructionLength,
      void* pJumpTo,
      JMPHook::JMPTypes JMPType,
      const std::string &sHookName);

    static bool UnregHook(const std::string &sHookName);

    static bool ApplyHook(const std::string &sHookName);
    static bool RestoreHook(const std::string &sHookName);

    static JMPHook* GetHook(const std::string &sHookName);

    static std::map<std::string, JMPHook*> GetHooks();

  private:
    JMPHookMgr();

    static JMPHookMgr* sm_pInstance;

    std::map<std::string, JMPHook*> m_mapHooks;
  };
}