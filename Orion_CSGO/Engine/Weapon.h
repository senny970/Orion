#pragma once

namespace E
{
	class CBaseAttributableItem;
	class CBaseViewModel;

	class CBaseWeapon : public SDK::IClientEntity
	{
	public:

    bool			GetWeaponReload();
		int				GetWeaponId();
    int				GetWeaponAmmo();
    float			GetNextPrimaryAttack();
    int				GetZoomLevel();
		int				GetWeaponType();

    CBaseAttributableItem*	GeteAttributableItem();
		CWeaponInfo*			GetWeaponInfo();

    const char*		GetPrintName();
		const char*		GetName();

	};

	class CBaseAttributableItem : public SDK::IClientEntity
	{
	public:

    int*			GetFallbackStatTrak();
		int*			GetItemIDHigh();
		int*			GetOriginalOwnerXuidLow();
    int*			GetItemDefinitionIndex();
		int*			GetFallbackPaintKit();
    int*			GetAccountID();
    int*			GetEntityQuality();
		float*			GetFallbackWear();
    int*			GetOriginalOwnerXuidHigh();
		int*			GetFallbackSeed();
		CBaseViewModel*	GetViewModel();

	};

	enum WEAPON_TYPE
	{
		WEAPON_TYPE_PISTOL ,
		WEAPON_TYPE_SHOTGUN ,
		WEAPON_TYPE_SNIPER ,
		WEAPON_TYPE_GRENADE ,
		WEAPON_TYPE_KNIFE ,
		WEAPON_TYPE_C4 ,
		WEAPON_TYPE_UNKNOWN ,
	};

	enum WEAPON_ID
	{
		WEAPON_NONE = 0 ,
		WEAPON_DEAGLE = 1 ,
		WEAPON_ELITE = 2 ,
		WEAPON_FIVESEVEN = 3 ,
		WEAPON_GLOCK = 4 ,
		WEAPON_AK47 = 7 ,
		WEAPON_AUG = 8 ,
		WEAPON_AWP = 9 ,
		WEAPON_FAMAS = 10 ,
		WEAPON_G3SG1 = 11 ,
		WEAPON_GALILAR = 13 ,
		WEAPON_M249 = 14 ,
		WEAPON_M4A1 = 16 ,
		WEAPON_MAC10 = 17 ,
		WEAPON_P90 = 19 ,
		WEAPON_UMP45 = 24 ,
		WEAPON_XM1014 = 25 ,
		WEAPON_BIZON = 26 ,
		WEAPON_MAG7 = 27 ,
		WEAPON_NEGEV = 28 ,
		WEAPON_SAWEDOFF = 29 ,
		WEAPON_TEC9 = 30 ,
		WEAPON_TASER = 31 ,
		WEAPON_HKP2000 = 32 ,
		WEAPON_MP7 = 33 ,
		WEAPON_MP9 = 34 ,
		WEAPON_NOVA = 35 ,
		WEAPON_P250 = 36 ,
		WEAPON_SCAR20 = 38 ,
		WEAPON_SG553 = 39 ,
		WEAPON_SSG08 = 40 ,
		WEAPON_KNIFE = 42 ,
		WEAPON_FLASHBANG = 43 ,
		WEAPON_HEGRENADE = 44 ,
		WEAPON_SMOKEGRENADE = 45 ,
		WEAPON_MOLOTOV = 46 ,
		WEAPON_DECOY = 47 ,
		WEAPON_INCGRENADE = 48 ,
		WEAPON_C4 = 49 ,
		WEAPON_KNIFE_T = 59 ,
		WEAPON_M4A1_SILENCER = 60 ,
		WEAPON_USP_SILENCER = 61 ,
		WEAPON_CZ75A = 63 ,
		WEAPON_REVOLVER = 64 ,
		WEAPON_KNIFE_BAYONET = 500 ,
		WEAPON_KNIFE_FLIP = 505 ,
		WEAPON_KNIFE_GUT = 506 ,
		WEAPON_KNIFE_KARAMBIT = 507 ,
		WEAPON_KNIFE_M9_BAYONET = 508 ,
		WEAPON_KNIFE_TACTICAL = 509 ,
		WEAPON_KNIFE_FALCHION = 512 ,
		WEAPON_KNIFE_SURVIVAL_BOWIE = 514 ,
		WEAPON_KNIFE_BUTTERFLY = 515 ,
		WEAPON_KNIFE_PUSH = 516
	};

  WEAPON_TYPE GetWeaponType(int iItemDefinitionIndex)
  {
    switch (iItemDefinitionIndex)
    {
      case WEAPON_DEAGLE:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_ELITE:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_FIVESEVEN:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_GLOCK:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_AK47:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_AUG:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_AWP:
        return WEAPON_TYPE_SNIPER;
      case WEAPON_FAMAS:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_G3SG1:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_GALILAR:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_M249:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_M4A1:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_MAC10:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_P90:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_UMP45:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_XM1014:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_BIZON:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_MAG7:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_NEGEV:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_SAWEDOFF:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_TEC9:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_TASER:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_HKP2000:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_MP7:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_MP9:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_NOVA:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_P250:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_SCAR20:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_SG553:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_SSG08:
        return WEAPON_TYPE_SNIPER;
      case WEAPON_KNIFE:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_FLASHBANG:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_HEGRENADE:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_SMOKEGRENADE:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_MOLOTOV:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_DECOY:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_INCGRENADE:
        return WEAPON_TYPE_GRENADE;
      case WEAPON_C4:
        return WEAPON_TYPE_C4;
      case WEAPON_KNIFE_T:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_M4A1_SILENCER:
        return WEAPON_TYPE_SHOTGUN;
      case WEAPON_USP_SILENCER:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_CZ75A:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_REVOLVER:
        return WEAPON_TYPE_PISTOL;
      case WEAPON_KNIFE_BAYONET:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_FLIP:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_GUT:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_KARAMBIT:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_M9_BAYONET:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_TACTICAL:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_FALCHION:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_SURVIVAL_BOWIE:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_BUTTERFLY:
        return WEAPON_TYPE_KNIFE;
      case WEAPON_KNIFE_PUSH:
        return WEAPON_TYPE_KNIFE;
      default:
        return WEAPON_TYPE_UNKNOWN;
    }
  }
}