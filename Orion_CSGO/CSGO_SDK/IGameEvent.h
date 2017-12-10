#pragma once

namespace SDK
{
	class IGameEvent
	{
	public:
		const char* GetName()
		{
			VirtualFn( const char* )( PVOID );
			return GetVMethod< OriginalFn >( this , VMTS::IGameEvent::GetName )( this );
		}

		int GetInt( const char* szKeyName , int nDefault = 0 )
		{
			VirtualFn( int )( PVOID , const char* , int );
			return GetVMethod< OriginalFn >( this , VMTS::IGameEvent::GetInt )( this , szKeyName , nDefault );
		}

		float GetFloat( const char *szkeyName = NULL , float defaultValue = 0.0f )
		{
			VirtualFn( float )( PVOID , const char* , float );
			return GetVMethod< OriginalFn >( this , VMTS::IGameEvent::GetFloat )( this , szkeyName , defaultValue );
		}

		const char* GetString( const char* szKeyName )
		{
			VirtualFn( const char* )( PVOID , const char* , int );
			return GetVMethod< OriginalFn >( this , VMTS::IGameEvent::GetString )( this , szKeyName , 0 );
		}

		void SetString( const char* szKeyName , const char* szValue )
		{
			VirtualFn( void )( PVOID , const char* , const char* );
			GetVMethod< OriginalFn >( this , VMTS::IGameEvent::SetString )( this , szKeyName , szValue );
		}
	};

	class IGameEventManager2
	{
	public:
		bool FireEventClientSide( IGameEvent* pEvent )
		{
			VirtualFn( bool )( PVOID , IGameEvent* );
			return GetVMethod< OriginalFn >( this , VMTS::IGameEventManager2::FireEventClientSide )( this , pEvent );
		}
	};
}