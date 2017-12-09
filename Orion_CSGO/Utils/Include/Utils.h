#pragma once

#include <string>
#include <array>
#include <vector>
#include <Windows.h>
#include <Psapi.h>
#include <d3d9.h>

#include "Patch.h"
#include "PatchMgr.h"
#include "VMTHook.h"
#include "VMTHookMgr.h"
#include "JMPHook.h"
#include "JMPHookMgr.h"

namespace U
{
  extern bool bDebug;

  enum ValueTypes
  {
    UnknownValue,
    IntValue,
    FloatValue,
    StringValue
  };

  IDirect3DDevice9* GetD3D();

  HMODULE GetModHandle(const std::string &moduleName);
  MODULEINFO GetModInfo(const std::string &moduleName);
  MODULEINFO GetModInfo(HMODULE hModule);

  ValueTypes GetValueType(const std::string &sInput);
  bool IsFloat(const std::string &sInput);
  bool IsInt(const std::string &sInput);

  void CopyToClipboard(const std::string &sInput);

  void OpenConsole(const std::string &consoleTitle);
  void CloseConsole();

  std::string HWID(int iHWIDGenerateDelayMs = 1000);

  std::string sha256(std::string input);

  std::string U16S_S8(const std::u16string &u16str);
  std::u16string S8_U16S(const std::string &str8);
  std::wstring S8_WS(const std::string &str8);
  std::string WS_S8(const std::wstring &wstr);

  std::vector<int> FindSeparatorIndexes(
    const std::string &str,
    const std::string &separator);

  std::vector<std::string> Split(
    const std::string &str,
    const std::string &separator);

  bool GeneratePattern(void* pDestination, DWORD size, std::string& pattern);

  void HexStringToPattern(
    const std::string &hexString,
    std::string &pattern,
    DWORD length);

  void PatternToHexString(
    const std::string &pattern,
    std::string &hexString);

  void PatternToHexString(
    const std::string &pattern,
    std::string &hexString,
    std::string &mask);

  std::string ByteToHex(unsigned char byte);

  DWORD CountPatternBytes(const std::string &pattern);

  void* FindPattern(
    const std::string &sModule,
    const std::string &pattern,
    const std::string &patternName = "",
    int iFinalOffset = 0);

  template<class T> T FindPattern(
    const std::string &sModule,
    const std::string &pattern,
    const std::string &patternName,
    int iFinalOffset)
  {
    return (T)FindPattern(sModule, pattern, patternName, iFinalOffset);
  }

  void* FindPattern(
    HMODULE hModule,
    const std::string &pattern,
    const std::string &patternName = "",
    int iFinalOffset = 0);

  template<class T> T FindPattern(
    HMODULE hModule,
    const std::string &pattern,
    const std::string &patternName,
    int iFinalOffset)
  {
    return (T)FindPattern(hModule, pattern, patternName, iFinalOffset);
  }

  void* FindPattern(
    MODULEINFO mInfo,
    const std::string &pattern,
    const std::string &patternName = "",
    int iFinalOffset = 0);

  template<class T> T FindPattern(
    MODULEINFO mInfo,
    const std::string &pattern,
    const std::string &patternName,
    int iFinalOffset)
  {
    return (T)FindPattern(mInfo, pattern, patternName, iFinalOffset);
  }

  void* FindIFace(void* pFnFactory, const std::string &sIFaceName);
  template <typename T> T FindIFace(void* pFnFactory, const std::string &name)
  {
    return (T)FindIFace(pFnFactory, name);
  }

  float Calc2dDistance(float point1[2], float point2[2]);
  float Calc3dDistance(float point1[3], float point2[3]);

  double Calc2dDistance(double point1[2], double point2[2]);
  double Calc3dDistance(double point1[3], double point2[3]);

  namespace XorString
  {
    constexpr auto time =
      (__TIME__[7] - '0') +
      (__TIME__[6] - '0') * 10 +
      (__TIME__[4] - '0') * 60 +
      (__TIME__[3] - '0') * 600 +
      (__TIME__[1] - '0') * 3600 +
      (__TIME__[0] - '0') * 36000;

    template <size_t size, int counter>
    class XSClass
    {
    public:
      template <size_t... IdxSequence>
      constexpr __forceinline XSClass(const char* str, std::index_sequence<IdxSequence...>)
        : m_cKey(static_cast<char>(time % 125 + 1)),
          m_Encrypted { Encrypt(str[IdxSequence])... }
      {

      }

      __forceinline decltype(auto) DecryptAll()
      {
        for (size_t i = 0; i < size; i++)
        {
          m_Encrypted[i] = Encrypt(m_Encrypted[i]);
        }
        m_Encrypted[size] = '\0';
        return m_Encrypted.data();
      }

    private:
      const char m_cKey;
      std::array<char, size + 1> m_Encrypted;

      constexpr char Encrypt(char symbol) const
      {
        return symbol ^ m_cKey;
      }
    }; // XSClass
  }
}

#define XS(str) (U::XorString::XSClass<sizeof(str) - 1, __COUNTER__> (str, std::make_index_sequence<sizeof(str) - 1>()).DecryptAll())
