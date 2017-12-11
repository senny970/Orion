#pragma once

namespace Engine
{
	typedef struct D3DTLVERTEX
	{
		float x;
		float y;
		float z;
		float rhw;
		D3DCOLOR dxColor;
	} *PD3DTLVERTEX;
	
	class CRender
	{
	public:

		CRender( IDirect3DDevice9* pDevice );
		~CRender();

    void OnResetDevice();
		void OnLostDevice();

		void BeginRender();
		void EndRender();

		void DrawLine( int x1 , int y1 , int x2 , int y2 , SDK::Color color );

		void DrawBox( int x , int y , int w , int h , SDK::Color color );
		void DrawFillBox( int x , int y , int w , int h , SDK::Color color );
		void DrawOutlineBox( int x , int y , int w , int h , SDK::Color color );

		void DrawCoalBox( int x , int y , int w , int h , SDK::Color color );
		void DrawOutlineCoalBox( int x , int y , int w , int h , SDK::Color color );

		void DrawWindow( int x , int y , int w , int h , SDK::Color Border , SDK::Color Background );

    void DrawVerBar(int x, int y, int w, int h, int val, SDK::Color color1, SDK::Color color2);
		void DrawHorBar( int x , int y , int w , int h , int val , SDK::Color color1 , SDK::Color color2 );
		
		void Text( int x , int y , bool center , bool shadow , SDK::Color color , const char* format , ... );

		IDirect3DDevice9*		m_pDevice;

	private:

		bool CreateObject();

		void SetVertexState();

		void CreateVertex( int x , int y , DWORD dxColor , PD3DTLVERTEX pVertext , DWORD index );

		ID3DXFont*				m_pFont;
		IDirect3DStateBlock9*	m_pStateBlockDraw;
		IDirect3DStateBlock9*	m_pStateBlockText;

		DWORD					dwOld_D3DRS_COLORWRITEENABLE;

	};
}