#pragma once

namespace E
{
	class NetVarManager
	{
	public:

		bool Init(SDK::ClientClass* pClientClass );

    bool HookProp(const char* tableName, const char* propName, SDK::RecvVarProxyFn function);
		DWORD GetOffset( const char* tableName , const char* propName );

	private:

		DWORD dwGetProp(SDK::RecvTable* recvTable , const char* propName , SDK::RecvProp** prop = 0 );
    DWORD dwGetProp(const char* tableName, const char* propName, SDK::RecvProp** prop = 0);

    SDK::RecvTable* GetTable( const char* tableName );
		vector<SDK::RecvTable*> m_tables;
	};

	extern NetVarManager g_NetVar;
}