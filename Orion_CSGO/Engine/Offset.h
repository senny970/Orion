#pragma once

#define FIND_W2MATRIX_PATTERN		"\xA1\x00\x00\x00\x00\x83\xF8\x01\x7E\x11\x69\xC8"

#define FIND_W2MATRIX_MASK			XS("x????xxxxxxx")

#define BASE_PLAYER					    XS("DT_BasePlayer")
#define BASE_PLAYER_WEAPONS			XS("m_hMyWeapons")
#define BASE_PLAYER_WERABLES		XS("m_hMyWearables")
#define BASE_PLAYER_VIEWMODEL		XS("m_hViewModel[0]")
#define BASE_PLAYER_TICKBASE		XS("m_nTickBase")
#define BASE_PLAYER_OBSMODE			XS("m_iObserverMode")
#define BASE_PLAYER_OBSERVER		XS("m_hObserverTarget")

#define CS_PLAYER					      XS("DT_CSPlayer")

#define CS_PLAYER_LIFESTATE			XS("m_lifeState")

#define CS_PLAYER_HASHELMET			XS("m_bHasHelmet")
#define CS_PLAYER_HASHDEFUSER		XS("m_bHasDefuser")
#define CS_PLAYER_ISSCOPED			XS("m_bIsScoped")

#define CS_PLAYER_FOVSTART			XS("m_iFOVStart")
#define CS_PLAYER_FLAGS				  XS("m_fFlags")

#define CS_PLAYER_HEALTH			  XS("m_iHealth")
#define CS_PLAYER_ARMOR				  XS("m_ArmorValue")
#define CS_PLAYER_TEAMNUM			  XS("m_iTeamNum")
#define CS_PLAYER_SHOTFIRED			XS("m_iShotsFired")
#define CS_PLAYER_AIMPUNCHANG		XS("m_aimPunchAngle")
#define CS_PLAYER_VIEWPUNCHANG	XS("m_viewPunchAngle")
#define CS_PLAYER_VECVELOCITY		XS("m_vecVelocity[0]")
#define CS_PLAYER_VECVIEW			  XS("m_vecViewOffset[0]")
#define CS_PLAYER_EYEANGLES			XS("m_angEyeAngles")
#define CS_PLAYER_ACTIVEWEAPON	XS("m_hActiveWeapon")

#define BASE_COMBAT_WEAPON			XS("DT_BaseCombatWeapon")
#define BASE_COMBAT_WEAPON_CLIP	XS("m_iClip1")
#define BASE_COMBAT_WEAPON_PRIM	XS("m_flNextPrimaryAttack")

#define BASE_ATTRIBUTABLE_ITEM				    XS("DT_BaseAttributableItem")
#define BASE_ATTRIBUTABLE_ITEM_INDEX		  XS("m_iItemDefinitionIndex")
#define BASE_ATTRIBUTABLE_ITEM_ID_HIGH		XS("m_iItemIDHigh")
#define BASE_ATTRIBUTABLE_ITEM_ACCOUNT_ID	XS("m_iAccountID")
#define BASE_ATTRIBUTABLE_ITEM_ENTITY_QAL	XS("m_iEntityQuality")
#define BASE_ATTRIBUTABLE_ITEM_OWNER_LOW	XS("m_OriginalOwnerXuidLow")
#define BASE_ATTRIBUTABLE_ITEM_OWNER_HIGH	XS("m_OriginalOwnerXuidHigh")
#define BASE_ATTRIBUTABLE_ITEM_PAINT_KIT	XS("m_nFallbackPaintKit")
#define BASE_ATTRIBUTABLE_ITEM_FALL_WEAR	XS("m_flFallbackWear")
#define BASE_ATTRIBUTABLE_ITEM_FALL_SEED	XS("m_nFallbackSeed")
#define BASE_ATTRIBUTABLE_ITEM_FALL_STAT	XS("m_nFallbackStatTrak")

#define BASE_ENTITY					              XS("DT_BaseEntity")
#define BASE_ENTITY_MODEL_INDEX		        XS("m_nModelIndex")
#define BASE_ENTITY_SPOTTED			          XS("m_bSpotted")

#define BASE_VIEW_MODEL				            XS("DT_BaseViewModel")
#define BASE_VIEW_MODEL_OWNER		          XS("m_hOwner")
#define BASE_VIEW_MODEL_WEAPON		        XS("m_hWeapon")

#define BASE_WEAPON_AWP				            XS("DT_WeaponAWP")
#define BASE_WEAPON_AWP_ZOOMLEVEL	        XS("m_zoomLevel")

namespace Engine
{
	namespace Offset
	{
		namespace Entity
		{

			extern DWORD m_hMyWeapons;
			extern DWORD m_hMyWearables;
			extern DWORD m_hViewModel;
			extern DWORD m_nTickBase;
			extern DWORD m_iObserverMode;
			extern DWORD m_hObserverTarget;
			
			extern DWORD m_lifeState;

			extern DWORD m_bHasHelmet;
			extern DWORD m_bHasDefuser;
			extern DWORD m_bIsScoped;

			extern DWORD m_iFOVStart;
			extern DWORD m_fFlags;
			extern DWORD m_iHealth;
			extern DWORD m_ArmorValue;
			extern DWORD m_iTeamNum;
			extern DWORD m_iShotsFired;

			extern DWORD m_aimPunchAngle;
			extern DWORD m_viewPunchAngle;
			
			extern DWORD m_vecVelocity;
			extern DWORD m_vecViewOffset;

			extern DWORD m_angEyeAngles;

			extern DWORD m_hActiveWeapon;

			extern DWORD m_iClip1;
			extern DWORD m_flNextPrimaryAttack;
			extern DWORD m_bCanReload;

			extern DWORD m_iItemDefinitionIndex;
			extern DWORD m_iItemIDHigh;
			extern DWORD m_iAccountID;
			extern DWORD m_iEntityQuality;
			extern DWORD m_OriginalOwnerXuidLow;
			extern DWORD m_OriginalOwnerXuidHigh;
			extern DWORD m_nFallbackPaintKit;
			extern DWORD m_flFallbackWear;
			extern DWORD m_nFallbackSeed;
			extern DWORD m_nFallbackStatTrak;

			extern DWORD m_nModelIndex;
			extern DWORD m_hOwner;
			extern DWORD m_hWeapon;
			extern DWORD m_bSpotted;

			extern DWORD m_zoomLevel;

		}

		bool	Initialize();
		float*	FindW2Matrix();
	}
}