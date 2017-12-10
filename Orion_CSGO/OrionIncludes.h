#pragma once

/********************************************************************

Orion instant hooks for Counter Strike Global Offensive by Astarion!

*********************************************************************/

using namespace std;

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#ifdef _DEBUG
#pragma comment(lib, "Utils/Lib/Utils_debug.lib")
#endif
#ifdef NDEBUG
#pragma comment(lib, "Utils/Lib/Utils_release.lib")
#endif
#include "Utils/Include/Utils.h"

#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <intrin.h>
#include <cmath>
#include <mmintrin.h>
#include <sstream>
#include <limits>
#include <map>

// ImGui
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_internal.h>

// VMT
#include "OrionGlobals\VMTS.h"

// SDK
#include "CSGO_SDK\BaseTypes.h"
#include "CSGO_SDK\Const.h"
#include "CSGO_SDK\Definitions.h"
#include "CSGO_SDK\InputEnums.h"

#include "CSGO_SDK\IHandleEntity.h"
#include "CSGO_SDK\CHandle.h"
#include "CSGO_SDK\CRC.h"
#include "CSGO_SDK\IAppSystem.h"
#include "CSGO_SDK\Vector.h"
#include "CSGO_SDK\Vplane.h"
#include "CSGO_SDK\Vector2D.h"
#include "CSGO_SDK\Vector4D.h"
#include "CSGO_SDK\QAngle.h"
#include "CSGO_SDK\VMatrix.h"
#include "CSGO_SDK\CGlobalVarsBase.h"
#include "CSGO_SDK\Color.h"
#include "CSGO_SDK\ButtonCode.h"
#include "CSGO_SDK\IClientUnknown.h"
#include "CSGO_SDK\IClientNetworkable.h"
#include "CSGO_SDK\IClientRenderable.h"
#include "CSGO_SDK\IClientThinkable.h"
#include "CSGO_SDK\IClientEntity.h"
#include "CSGO_SDK\IClientEntityList.h"
#include "CSGO_SDK\PlayerInfo.h"
#include "CSGO_SDK\IVEngineClient.h"
#include "CSGO_SDK\IEngineTrace.h"
#include "CSGO_SDK\RecvCommon.h"
#include "CSGO_SDK\Recv.h"
#include "CSGO_SDK\ClientClass.h"
#include "CSGO_SDK\CInput.h"
#include "CSGO_SDK\IClientMode.h"
#include "CSGO_SDK\IBaseClientDll.h"
#include "CSGO_SDK\IVModelInfoClient.h"
#include "CSGO_SDK\ICollideable.h"
#include "CSGO_SDK\IEngineSound.h"
#include "CSGO_SDK\IVModelRender.h"
#include "CSGO_SDK\IVRenderView.h"
#include "CSGO_SDK\IMaterialSystem.h"
#include "CSGO_SDK\IMaterial.h"
#include "CSGO_SDK\ISurface.h"
#include "CSGO_SDK\IGameEvent.h"
#include "CSGO_SDK\TextureGroupNames.h"

// Orion
#include "OrionGlobals\CONFIG.h"
#include "OrionGlobals\DEFS.h"
#include "OrionGlobals\GLOBALS.h"

// ENGINE
#include "Engine\NetVar.h"
#include "Engine\Offset.h"
#include "Engine\Entity.h"
#include "Engine\Weapon.h"

// CHEATS
#include "Cheats\C_Cheat.h"
#include "Cheats\C_CheatMgr.h"
#include "Cheats\C_Bhop.h"
#include "Cheats\C_FakeLag.h"
#include "Cheats\C_Radar.h"

// HOOKS
#include "Hooks.h"

// MAIN
#include "MainHandler.h"

