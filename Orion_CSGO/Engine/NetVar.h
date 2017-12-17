#pragma once

namespace Engine
{
	class NetVarManager
	{
	public:

		bool Init(SDK::ClientClass* pClientClass );

		DWORD GetOffset( const char* tableName , const char* propName );
		bool HookProp( const char* tableName , const char* propName , SDK::RecvVarProxyFn function );

	private:

		DWORD dwGetProp( const char* tableName , const char* propName , SDK::RecvProp** prop = 0 );
		DWORD dwGetProp(SDK::RecvTable* recvTable , const char* propName , SDK::RecvProp** prop = 0 );

    SDK::RecvTable* GetTable( const char* tableName );
		vector<SDK::RecvTable*> m_tables;
	};

	extern NetVarManager g_NetVar;
}