#include "../OrionIncludes.h"

namespace Engine
{

	char* CBaseEntity::GetPlayerName()
	{
		if ( IsPlayer() )
		{
			static SDK::PlayerInfo Info;

			if ( G::pEngine->GetPlayerInfo( EntIndex() , &Info ) )
				return Info.m_szPlayerName;
		}

		return "";
	}

	bool CBaseEntity::IsPlayer()
	{
		typedef bool( __thiscall* IsPlayerFn )( void* );
		return GetVMethod<IsPlayerFn>( this , 152 )( this );
	}

	bool CBaseEntity::IsAlive()
	{
		return ( !IsDead() && GetHealth() > 0 && !IsDormant() );
	}

	bool CBaseEntity::IsDead()
	{
		BYTE LifeState = *(PBYTE)( (DWORD)this + Offset::Entity::m_lifeState );
		return ( LifeState != LIFE_ALIVE );
	}

	bool CBaseEntity::IsVisible( CBaseEntity* pLocalEntity )
	{
		if ( !pLocalEntity->IsAlive() )
			return false;

		SDK::Vector vSrcOrigin = pLocalEntity->GetEyePosition();

		if ( vSrcOrigin.IsZero() || !vSrcOrigin.IsValid() )
			return false;

		BYTE bHitBoxCheckVisible[6] = {
      SDK::HITBOX_HEAD,
      SDK::HITBOX_BODY,
      SDK::HITBOX_RIGHT_FOOT,
      SDK::HITBOX_LEFT_FOOT,
      SDK::HITBOX_RIGHT_HAND,
      SDK::HITBOX_LEFT_HAND,
		};

    SDK::CTraceFilter filter;

		filter.pSkip = pLocalEntity;

		for ( int nHit = 0; nHit < 6; nHit++ )
		{
      SDK::Vector vHitBox = GetHitboxPosition( bHitBoxCheckVisible[nHit] );

			if ( vHitBox.IsZero() || !vHitBox.IsValid() )
				continue;

      SDK::trace_t tr;
      SDK::Ray_t ray;

			ray.Init( vSrcOrigin , vHitBox );

			G::pEngineTrace->TraceRay( ray , PlayerVisibleMask , &filter , &tr );

      if (tr.m_pEnt == (IClientEntity*)this && !tr.allsolid)
      {
        return true;
      }
		}

		return false;
	}

	bool CBaseEntity::HasHelmet()
	{
		return *(bool*)( (DWORD)this + Offset::Entity::m_bHasHelmet );
	}

	bool CBaseEntity::HasDefuser()
	{
		return *(bool*)( (DWORD)this + Offset::Entity::m_bHasDefuser );
	}

	bool* CBaseEntity::IsSpotted()
	{
		return (bool*)( (DWORD)this + Offset::Entity::m_bSpotted );
	}

	int	CBaseEntity::GetFovStart()
	{
		return *(PINT)( (DWORD)this + Offset::Entity::m_iFOVStart );
	}

	int	CBaseEntity::GetFlags()
	{
		return *(PINT)( (DWORD)this + Offset::Entity::m_fFlags );
	}
	
	int CBaseEntity::GetHealth()
	{
		return *(PINT)( (DWORD)this + Offset::Entity::m_iHealth );
	}

	int	CBaseEntity::GetArmor()
	{
		return *(PINT)( (DWORD)this + Offset::Entity::m_ArmorValue );
	}

	int	CBaseEntity::GetTeam()
	{
		return *(PINT)( (DWORD)this + Offset::Entity::m_iTeamNum );
	}

  float* CBaseEntity::GetFlashDuration()
  {
    return (float*)((DWORD)this + Offset::Entity::m_flFlashDuration);
  }

	int CBaseEntity::GetShotsFired()
	{
		return *(PINT)( (DWORD)this + (DWORD)Offset::Entity::m_iShotsFired );
	}

	int CBaseEntity::GetIsScoped()
	{
		return *(PINT)( (DWORD)this + (DWORD)Offset::Entity::m_bIsScoped );
	}

	int	CBaseEntity::GetTickBase()
	{
		return *(PINT)( (DWORD)this + (DWORD)Offset::Entity::m_nTickBase );
	}

  SDK::ObserverMode_t CBaseEntity::GetObserverMode()
	{
		return *(SDK::ObserverMode_t*)( (DWORD)this + (DWORD)Offset::Entity::m_iObserverMode );
	}

	PVOID CBaseEntity::GetObserverTarget()
	{
		return ( PVOID )*(PDWORD)( (DWORD)this + (DWORD)Offset::Entity::m_hObserverTarget );
	}
	
	PVOID CBaseEntity::GetActiveWeapon()
	{
		return (PVOID)( (DWORD)this + (DWORD)Offset::Entity::m_hActiveWeapon );
	}
	
	CBaseWeapon* CBaseEntity::GetBaseWeapon()
	{
		return (CBaseWeapon*)G::pEntityList->GetClientEntityFromHandle( ( PVOID )*(PDWORD)GetActiveWeapon() );
	}

	UINT* CBaseEntity::GetWeapons()
	{
		// DT_BasePlayer -> m_hMyWeapons
		return (UINT*)( (DWORD)this + Offset::Entity::m_hMyWeapons );
	}

	UINT* CBaseEntity::GetWearables()
	{
		return (UINT*)( (DWORD)this + Offset::Entity::m_hMyWearables );
	}

	CBaseViewModel* CBaseEntity::GetViewModel()
	{
		// DT_BasePlayer -> m_hViewModel
		return (CBaseViewModel*)G::pEntityList->GetClientEntityFromHandle( ( PVOID )*(PDWORD)( (DWORD)this + Offset::Entity::m_hViewModel ) );
	}

  SDK::Vector CBaseEntity::GetAimPunchAngle()
	{
		return *(SDK::Vector*)( (DWORD)this + Offset::Entity::m_aimPunchAngle );
	}

  SDK::Vector CBaseEntity::GetViewPunchAngle()
	{
		return *(SDK::Vector*)( (DWORD)this + Offset::Entity::m_viewPunchAngle );
	}

  SDK::Vector CBaseEntity::GetVelocity()
	{
		return *(SDK::Vector*)( (DWORD)this + Offset::Entity::m_vecVelocity );
	}

  SDK::Vector CBaseEntity::GetViewOffset()
	{
		return *(SDK::Vector*)( (DWORD)this + Offset::Entity::m_vecViewOffset );
	}

  SDK::Vector CBaseEntity::GetEyePosition()
	{
		return GetRenderOrigin() + GetViewOffset();
	}

  SDK::QAngle CBaseEntity::GetEyeAngles()
	{
		return *reinterpret_cast<SDK::QAngle*>( (DWORD)this + Offset::Entity::m_angEyeAngles );
	}
	
  SDK::Vector CBaseEntity::GetBonePosition( int nBone )
	{
    SDK::Vector vRet;
    SDK::matrix3x4_t MatrixArray[MAXSTUDIOBONES];

		if ( !SetupBones( MatrixArray , MAXSTUDIOBONES , BONE_USED_BY_HITBOX , G::pGlobals->curtime ) )
			return vRet;

    SDK::matrix3x4_t HitboxMatrix = MatrixArray[nBone];

		vRet = SDK::Vector( HitboxMatrix[0][3] , HitboxMatrix[1][3] , HitboxMatrix[2][3] );

		return vRet;
	}

  SDK::studiohdr_t* CBaseEntity::GetStudioModel()
	{
		const SDK::model_t* model = nullptr;

		model = GetModel();
		
		if ( !model )
			return nullptr;

    SDK::studiohdr_t* pStudioModel = G::pModelInfo->GetStudioModel( model );

		if ( !pStudioModel )
			return nullptr;

		return pStudioModel;
	}

  SDK::mstudiobone_t* CBaseEntity::GetBone( int nBone )
	{
    SDK::mstudiobone_t* pBoneBox = nullptr;

    SDK::studiohdr_t* pStudioModel = GetStudioModel();

		if ( !pStudioModel )
			return pBoneBox;

    SDK::mstudiobone_t* pBone = pStudioModel->pBone( nBone );

		if ( !pBone )
			return nullptr;

		return pBone;
	}

  SDK::mstudiobbox_t* CBaseEntity::GetHitBox( int nHitbox )
	{
		if ( nHitbox < 0 || nHitbox >= SDK::HITBOX_MAX )
			return nullptr;

    SDK::mstudiohitboxset_t* pHitboxSet = nullptr;
    SDK::mstudiobbox_t* pHitboxBox = nullptr;

		pHitboxSet = GetHitBoxSet();

		if ( !pHitboxSet )
			return pHitboxBox;

		pHitboxBox = pHitboxSet->pHitbox( nHitbox );

		if ( !pHitboxBox )
			return nullptr;

		return pHitboxBox;
	}

  SDK::mstudiohitboxset_t* CBaseEntity::GetHitBoxSet()
	{
    SDK::studiohdr_t* pStudioModel = nullptr;
    SDK::mstudiohitboxset_t* pHitboxSet = nullptr;

		pStudioModel = GetStudioModel();

		if ( !pStudioModel )
			return pHitboxSet;

		pHitboxSet = pStudioModel->pHitboxSet( 0 );

		if ( !pHitboxSet )
			return nullptr;

		return pHitboxSet;
	}

  SDK::Vector CBaseEntity::GetHitboxPosition( int nHitbox )
	{
    SDK::matrix3x4_t MatrixArray[MAXSTUDIOBONES];
    SDK::Vector vRet , vMin , vMax;

    vRet = SDK::Vector( 0 , 0 , 0 );

    SDK::mstudiobbox_t* pHitboxBox = GetHitBox( nHitbox );

		if ( !pHitboxBox || !IsAlive() )
			return vRet;
		
		if ( !SetupBones( MatrixArray , MAXSTUDIOBONES , BONE_USED_BY_HITBOX , 0/*G::pGlobals->curtime*/ ) )
			return vRet;

		if ( !pHitboxBox->m_Bone || !pHitboxBox->m_vBbmin.IsValid() || !pHitboxBox->m_vBbmax.IsValid() )
			return vRet;
						
		VectorTransform( pHitboxBox->m_vBbmin , MatrixArray[pHitboxBox->m_Bone] , vMin );
		VectorTransform( pHitboxBox->m_vBbmax , MatrixArray[pHitboxBox->m_Bone] , vMax );

		vRet = ( vMin + vMax ) * 0.5f;

		return vRet;
	}

	int	CBaseViewModel::GetModelIndex()
	{
		// DT_BaseViewModel -> m_nModelIndex
		return *(int*)( (DWORD)this + Offset::Entity::m_nModelIndex );
	}

	void CBaseViewModel::SetModelIndex( int nModelIndex )
	{
		VirtualFn( void )( PVOID , int );
		GetVMethod< OriginalFn >( this , 75 )( this , nModelIndex );
		// DT_BaseViewModel -> m_nModelIndex
		//*(int*)( (DWORD)this + Offset::Entity::m_nModelIndex ) = nModelIndex;
	}

	void CBaseViewModel::SetWeaponModel( const char* Filename , IClientEntity* Weapon )
	{
		typedef void( __thiscall* SetWeaponModelFn )( void* , const char* , IClientEntity* );
		return GetVMethod<SetWeaponModelFn>( this , 242 )( this , Filename , Weapon );
	}

	DWORD CBaseViewModel::GetOwner()
	{
		// DT_BaseViewModel -> m_hOwner
		return *(PDWORD)( (DWORD)this + Offset::Entity::m_hOwner );
	}

	DWORD CBaseViewModel::GetWeapon()
	{
		// DT_BaseViewModel -> m_hWeapon
		return *(PDWORD)( (DWORD)this + Offset::Entity::m_hWeapon );
	}
}