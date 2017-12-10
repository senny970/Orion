#pragma once

namespace M
{
  void InitAll(HINSTANCE hDllInstance);
  void InitGlobals(HINSTANCE hDllInstance);
  void InitImGui();
  void InitHooks();
  void InitEngine();

  void RegCheats();

  void ReleaseAll();
}

