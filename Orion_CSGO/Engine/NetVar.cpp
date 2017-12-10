#include "../OrionIncludes.h"

namespace E
{

	NetVarManager g_NetVar;

	bool NetVarManager::Init(SDK::ClientClass* pClientClass )
	{
		if ( !pClientClass )
			return false;

		while ( pClientClass )
		{
      SDK::RecvTable* recvTable = pClientClass->m_pRecvTable;
			m_tables.push_back( recvTable );
			pClientClass = pClientClass->m_pNext;
		}

		return true;
	}

	DWORD NetVarManager::GetOffset( const char* tableName , const char* propName )
	{
		int offset = dwGetProp( tableName , propName );

		if ( !offset )
			return 0;

		return offset;
	}

	bool NetVarManager::HookProp( const char* tableName , const char* propName , SDK::RecvVarProxyFn function )
	{
    SDK::RecvProp *recvProp = 0;

		dwGetProp( tableName , propName , &recvProp );

		if ( !recvProp )
		{
			return false;
		}

		recvProp->m_ProxyFn = function;

		return true;
	}

	DWORD NetVarManager::dwGetProp( const char* tableName , const char* propName , SDK::RecvProp** prop )
	{
    SDK::RecvTable *recvTable = GetTable( tableName );

		if ( !recvTable )
			return 0;

		int offset = dwGetProp( recvTable , propName , prop );

		if ( !offset )
			return 0;

		return offset;
	}

	DWORD NetVarManager::dwGetProp(SDK::RecvTable* recvTable , const char* propName , SDK::RecvProp** prop )
	{
		int extraOffset = 0;

		for ( int i = 0; i < recvTable->m_nProps; ++i )
		{
      SDK::RecvProp *recvProp = &recvTable->m_pProps[i];

      SDK::RecvTable *child = recvProp->m_pDataTable;

			if ( child && ( child->m_nProps > 0 ) )
			{
				int tmp = dwGetProp( child , propName , prop );

				if ( tmp )
				{
					extraOffset += ( recvProp->m_Offset + tmp );
				}
			}

			if ( lstrcmpiA( recvProp->m_pVarName , propName ) )
				continue;

			if ( prop )
				*prop = recvProp;

			return ( recvProp->m_Offset + extraOffset );
		}

		return extraOffset;
	}

  SDK::RecvTable* NetVarManager::GetTable( const char* tableName )
	{
		if ( m_tables.empty() )
			return 0;

		for each (SDK::RecvTable *table in m_tables )
		{
			if ( !table )
			{
				continue;
			}

			if ( strcmp( table->m_pNetTableName , tableName ) == 0 )
			{
				return table;
			}
		}

		return 0;
	}
}