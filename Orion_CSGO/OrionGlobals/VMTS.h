#pragma once

namespace SDK
{
  namespace VMTS
  {
    namespace IClientMode
    {
      enum
      {
        OverrideView = 18,
        CreateMove = 24,
        GetViewModelFOV = 35
      };
    }
    namespace IBaseClientDLL
    {
      enum
      {
        CreateMove = 21,
        FrameStageNotify = 36
      };
    }
    namespace IEngineSound
    {
      enum
      {
        EmitSound1 = 5,
        EmitSound2 = 6
      };
    }
    namespace IGameEvent
    {
      enum
      {
        GetName = 1,
        GetInt = 6,
        GetFloat = 8,
        GetString = 9,
        SetString = 16
      };
    }
    namespace IGameEventManager2
    {
      enum
      {
        FireEventClientSide = 9
      };
    }
    namespace ISurface
    {
      enum
      {
        DrawSetColor1 = 14,
        DrawSetColor2 = 15,
        DrawFilledRect = 16,
        DrawOutlinedRect = 18,
        DrawLine = 19,
        DrawSetTextFont = 23,
        DrawSetTextColor = 24,
        DrawSetTextPos = 26,
        DrawPrintText = 28,
        FontCreate = 71,
        SetFontGlyphSet = 72,
        GetTextSize = 79,
        PlaySoundFn = 82
      };
    }
    namespace IVModelRender
    {
      enum
      {
        DrawModelExecute = 21,
      };
    }
  }
}