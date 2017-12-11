#pragma once

#pragma region MASKS

#define   DISPSURF_FLAG_SURFACE           (1<<0)
#define   DISPSURF_FLAG_WALKABLE          (1<<1)
#define   DISPSURF_FLAG_BUILDABLE         (1<<2)
#define   DISPSURF_FLAG_SURFPROP1         (1<<3)
#define   DISPSURF_FLAG_SURFPROP2         (1<<4)

#define   CONTENTS_EMPTY                0

#define   CONTENTS_SOLID                0x1       
#define   CONTENTS_WINDOW               0x2
#define   CONTENTS_AUX                  0x4
#define   CONTENTS_GRATE                0x8
#define   CONTENTS_SLIME                0x10
#define   CONTENTS_WATER                0x20
#define   CONTENTS_BLOCKLOS             0x40 
#define   CONTENTS_OPAQUE               0x80 
#define   LAST_VISIBLE_CONTENTS         CONTENTS_OPAQUE

#define   ALL_VISIBLE_CONTENTS            (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))

#define   CONTENTS_TESTFOGVOLUME        0x100
#define   CONTENTS_UNUSED               0x200     
#define   CONTENTS_BLOCKLIGHT           0x400
#define   CONTENTS_TEAM1                0x800 
#define   CONTENTS_TEAM2                0x1000 
#define   CONTENTS_IGNORE_NODRAW_OPAQUE 0x2000
#define   CONTENTS_MOVEABLE             0x4000
#define   CONTENTS_AREAPORTAL           0x8000
#define   CONTENTS_PLAYERCLIP           0x10000
#define   CONTENTS_MONSTERCLIP          0x20000
#define   CONTENTS_CURRENT_0            0x40000
#define   CONTENTS_CURRENT_90           0x80000
#define   CONTENTS_CURRENT_180          0x100000
#define   CONTENTS_CURRENT_270          0x200000
#define   CONTENTS_CURRENT_UP           0x400000
#define   CONTENTS_CURRENT_DOWN         0x800000

#define   CONTENTS_ORIGIN               0x1000000 

#define   CONTENTS_MONSTER              0x2000000 
#define   CONTENTS_DEBRIS               0x4000000
#define   CONTENTS_DETAIL               0x8000000 
#define   CONTENTS_TRANSLUCENT          0x10000000
#define   CONTENTS_LADDER               0x20000000
#define   CONTENTS_HITBOX               0x40000000

#define   SURF_LIGHT                    0x0001 
#define   SURF_SKY2D                    0x0002 
#define   SURF_SKY                      0x0004 
#define   SURF_WARP                     0x0008 
#define   SURF_TRANS                    0x0010
#define   SURF_NOPORTAL                 0x0020 
#define   SURF_TRIGGER                  0x0040 
#define   SURF_NODRAW                   0x0080 

#define   SURF_HINT                     0x0100 

#define   SURF_SKIP                     0x0200   
#define   SURF_NOLIGHT                  0x0400   
#define   SURF_BUMPLIGHT                0x0800   
#define   SURF_NOSHADOWS                0x1000   
#define   SURF_NODECALS                 0x2000   
#define   SURF_NOPAINT                  SURF_NODECALS
#define   SURF_NOCHOP                   0x4000   
#define   SURF_HITBOX                   0x8000   

// -----------------------------------------------------
// spatial content masks - used for spatial queries (traceline,etc.)
// -----------------------------------------------------
#define   MASK_ALL                      (0xFFFFFFFF)
#define   MASK_SOLID                    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define   MASK_PLAYERSOLID              (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define   MASK_NPCSOLID                 (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define   MASK_NPCFLUID                 (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER)
#define   MASK_WATER                    (CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME)
#define   MASK_OPAQUE                   (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE)
#define   MASK_OPAQUE_AND_NPCS          (MASK_OPAQUE|CONTENTS_MONSTER)
#define   MASK_BLOCKLOS                 (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_BLOCKLOS)
#define   MASK_BLOCKLOS_AND_NPCS        (MASK_BLOCKLOS|CONTENTS_MONSTER)
#define   MASK_VISIBLE                  (MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define   MASK_VISIBLE_AND_NPCS         (MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define   MASK_SHOT                     (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
#define   MASK_SHOT_BRUSHONLY           (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_DEBRIS)
#define   MASK_SHOT_HULL                (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE)
#define   MASK_SHOT_PORTAL              (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER)
#define   MASK_SOLID_BRUSHONLY          (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE)
#define   MASK_PLAYERSOLID_BRUSHONLY    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE)
#define   MASK_NPCSOLID_BRUSHONLY       (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define   MASK_NPCWORLDSTATIC           (CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define   MASK_NPCWORLDSTATIC_FLUID     (CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP)
#define   MASK_SPLITAREAPORTAL          (CONTENTS_WATER|CONTENTS_SLIME)
#define   MASK_CURRENT                  (CONTENTS_CURRENT_0|CONTENTS_CURRENT_90|CONTENTS_CURRENT_180|CONTENTS_CURRENT_270|CONTENTS_CURRENT_UP|CONTENTS_CURRENT_DOWN)
#define   MASK_DEADSOLID                (CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_GRATE)
#define	  PlayerVisibleMask				(CONTENTS_HITBOX | CONTENTS_MONSTER | CONTENTS_DEBRIS | CONTENTS_MOVEABLE | CONTENTS_SOLID | CONTENTS_WINDOW | CONTENTS_GRATE)

#pragma endregion

namespace SDK
{
	class IHandleEntity;
	struct Ray_t;
	class CGameTrace;
	typedef CGameTrace trace_t;
	class ICollideable;
	class ITraceListData;
	class CPhysCollide;
	struct cplane_t;
	struct virtualmeshlist_t;

	template< class T , class I = int >
	class CUtlMemory {};

	template< class T , class A = CUtlMemory<T> >
	class CUtlVector {};

	enum hitgroup_t {
		HITGROUP_GENERIC ,
		HITGROUP_HEAD ,
		HITGROUP_CHEST ,
		HITGROUP_STOMACH ,
		HITGROUP_LEFTARM ,
		HITGROUP_RIGHTARM ,
		HITGROUP_LEFTLEG ,
		HITGROUP_RIGHTLEG ,
		HITGROUP_GEAR = 10 ,
	};

	enum class TraceType {
		TRACE_EVERYTHING = 0 ,
		TRACE_WORLD_ONLY ,
		TRACE_ENTITIES_ONLY ,
		TRACE_EVERYTHING_FILTER_PROPS ,
	};

	class ITraceFilter
	{
	public:
		virtual bool ShouldHitEntity( IHandleEntity *pEntity , int contentsMask ) = 0;
		virtual TraceType GetTraceType() const = 0;
	};


	//-----------------------------------------------------------------------------
	// Classes are expected to inherit these + implement the ShouldHitEntity method
	//-----------------------------------------------------------------------------

	// This is the one most normal traces will inherit from
	class CTraceFilter : public ITraceFilter {
	public:
		bool ShouldHitEntity( IHandleEntity* pEntityHandle , int /*contentsMask*/ ) {
			return !( pEntityHandle == pSkip );
		}
		virtual TraceType GetTraceType() const {
			return TraceType::TRACE_EVERYTHING;
		}
		void* pSkip;
	};

	class CTraceFilterEntitiesOnly : public ITraceFilter {
	public:
		virtual TraceType GetTraceType() const {
			return TraceType::TRACE_ENTITIES_ONLY;
		}
	};


	//-----------------------------------------------------------------------------
	// Classes need not inherit from these
	//-----------------------------------------------------------------------------
	class CTraceFilterWorldOnly : public ITraceFilter {
	public:
		bool ShouldHitEntity( IHandleEntity* /*pServerEntity*/ , int /*contentsMask*/ ) {
			return false;
		}
		virtual TraceType GetTraceType() const {
			return TraceType::TRACE_WORLD_ONLY;
		}
	};

	class CTraceFilterWorldAndPropsOnly : public ITraceFilter {
	public:
		bool ShouldHitEntity( IHandleEntity* /*pServerEntity*/ , int /*contentsMask*/ ) {
			return false;
		}
		virtual TraceType GetTraceType() const {
			return TraceType::TRACE_EVERYTHING;
		}
	};

	class CTraceFilterHitAll : public CTraceFilter {
	public:
		virtual bool ShouldHitEntity( IHandleEntity* /*pServerEntity*/ , int /*contentsMask*/ ) {
			return true;
		}
	};


	enum class DebugTraceCounterBehavior_t {
		kTRACE_COUNTER_SET = 0 ,
		kTRACE_COUNTER_INC ,
	};

	//-----------------------------------------------------------------------------
	// Enumeration interface for EnumerateLinkEntities
	//-----------------------------------------------------------------------------
	class IEntityEnumerator
	{
	public:
		// This gets called with each handle
		virtual bool EnumEntity( IHandleEntity *pHandleEntity ) = 0;
	};


	struct BrushSideInfo_t {
		Vector4D plane;               // The plane of the brush side
		unsigned short bevel;    // Bevel plane?
		unsigned short thin;     // Thin?
	};

	class CPhysCollide;

	struct vcollide_t {
		unsigned short solidCount : 15;
		unsigned short isPacked : 1;
		unsigned short descSize;
		// VPhysicsSolids
		CPhysCollide   **solids;
		char           *pKeyValues;
		void           *pUserData;
	};

	struct cmodel_t {
		Vector         mins , maxs;
		Vector         origin;        // for sounds or lights
		int            headnode;
		vcollide_t     vcollisionData;
	};

	struct csurface_t {
		const char     *name;
		short          surfaceProps;
		unsigned short flags;         // BUGBUG: These are declared per surface, not per material, but this database is per-material now
	};

	//-----------------------------------------------------------------------------
	// A ray...
	//-----------------------------------------------------------------------------
	struct Ray_t {
		VectorAligned  m_Start;  // starting point, centered within the extents
		VectorAligned  m_Delta;  // direction + length of the ray
		VectorAligned  m_StartOffset; // Add this to m_Start to get the actual ray start
		VectorAligned  m_Extents;     // Describes an axis aligned box extruded along a ray
		const matrix3x4_t *m_pWorldAxisTransform;
		bool m_IsRay;  // are the extents zero?
		bool m_IsSwept;     // is delta != 0?

		Ray_t() : m_pWorldAxisTransform( NULL ) {}

		void Init( Vector const& start , Vector const& end )
    {
			m_Delta = end - start;

			m_IsSwept = ( m_Delta.LengthSqr() != 0 );

      m_IsRay = true;
      m_pWorldAxisTransform = NULL;

      m_StartOffset.Init();
			m_Extents.Init();

			// Offset m_Start to be in the center of the box...
			VectorCopy( start , m_Start );
		}

		void Init( Vector const& start , Vector const& end , Vector const& mins , Vector const& maxs ) {
			m_Delta = end - start;

			m_pWorldAxisTransform = NULL;
			m_IsSwept = ( m_Delta.LengthSqr() != 0 );

			m_Extents = maxs - mins;
			m_Extents *= 0.5f;
			m_IsRay = ( m_Extents.LengthSqr() < 1e-6 );

			// Offset m_Start to be in the center of the box...
			m_StartOffset = maxs + mins;
			m_StartOffset *= 0.5f;
			m_Start = start + m_StartOffset;
			m_StartOffset *= -1.0f;
		}
		Vector InvDelta() const {
			Vector vecInvDelta;
			for ( int iAxis = 0; iAxis < 3; ++iAxis )
			{
				if ( m_Delta[iAxis] != 0.0f )
				{
					vecInvDelta[iAxis] = 1.0f / m_Delta[iAxis];
				}
				else
				{
					vecInvDelta[iAxis] = FLT_MAX;
				}
			}
			return vecInvDelta;
		}

	private:
	};

	class CBaseTrace {
	public:
		bool IsDispSurface( void ) { return ( ( dispFlags & DISPSURF_FLAG_SURFACE ) != 0 ); }
		bool IsDispSurfaceWalkable( void ) { return ( ( dispFlags & DISPSURF_FLAG_WALKABLE ) != 0 ); }
		bool IsDispSurfaceBuildable( void ) { return ( ( dispFlags & DISPSURF_FLAG_BUILDABLE ) != 0 ); }
		bool IsDispSurfaceProp1( void ) { return ( ( dispFlags & DISPSURF_FLAG_SURFPROP1 ) != 0 ); }
		bool IsDispSurfaceProp2( void ) { return ( ( dispFlags & DISPSURF_FLAG_SURFPROP2 ) != 0 ); }

	public:

		// these members are aligned!!
		Vector         startpos;                // start position
		Vector         endpos;                       // final position
		cplane_t       plane;                        // surface normal at impact

		float          fraction;                // time completed, 1.0 = didn't hit anything

		int            contents;                // contents on other side of surface hit
		unsigned short dispFlags;                    // displacement flags for marking surfaces with data

		bool           allsolid;                // if true, plane is not valid
		bool           startsolid;                   // if true, the initial point was in a solid area

		CBaseTrace() {}

	};

	class CGameTrace : public CBaseTrace {
	public:
		bool DidHit() const;
		bool IsVisible() const;

	public:

		float               fractionleftsolid;  // time we left a solid, only valid if we started in solid
		csurface_t          surface;            // surface hit (impact surface)
		int                 hitgroup;           // 0 == generic, non-zero is specific body part
		short               physicsbone;        // physics bone hit by trace in studio
		unsigned short      worldSurfaceIndex;  // Index of the msurface2_t, if applicable
		IClientEntity*      m_pEnt;
		int                 hitbox;                       // box hit by trace in studio

		CGameTrace() {}

	private:
		// No copy constructors allowed
		CGameTrace( const CGameTrace& other ) :
			fractionleftsolid( other.fractionleftsolid ) ,
			surface( other.surface ) ,
			hitgroup( other.hitgroup ) ,
			physicsbone( other.physicsbone ) ,
			worldSurfaceIndex( other.worldSurfaceIndex ) ,
			m_pEnt( other.m_pEnt ) ,
			hitbox( other.hitbox ) {
			startpos = other.startpos;
			endpos = other.endpos;
			plane = other.plane;
			fraction = other.fraction;
			contents = other.contents;
			dispFlags = other.dispFlags;
			allsolid = other.allsolid;
			startsolid = other.startsolid;
		}

		CGameTrace& CGameTrace::operator=( const CGameTrace& other ) {
			startpos = other.startpos;
			endpos = other.endpos;
			plane = other.plane;
			fraction = other.fraction;
			contents = other.contents;
			dispFlags = other.dispFlags;
			allsolid = other.allsolid;
			startsolid = other.startsolid;
			fractionleftsolid = other.fractionleftsolid;
			surface = other.surface;
			hitgroup = other.hitgroup;
			physicsbone = other.physicsbone;
			worldSurfaceIndex = other.worldSurfaceIndex;
			m_pEnt = other.m_pEnt;
			hitbox = other.hitbox;
			return *this;
		}
	};

	inline bool CGameTrace::DidHit() const {
		return fraction < 1 || allsolid || startsolid;
	}

	inline bool CGameTrace::IsVisible() const {
		return fraction > 0.97f;
	}

	class IEngineTrace
	{
	public:
		virtual int		GetPointContents( const Vector &vecAbsPosition , int contentsMask = MASK_ALL , IHandleEntity** ppEntity = NULL ) = 0;
		virtual int		GetPointContents_WorldOnly( const Vector &vecAbsPosition , int contentsMask = MASK_ALL ) = 0;
		virtual int		GetPointContents_Collideable( ICollideable *pCollide , const Vector &vecAbsPosition ) = 0;
		virtual void	ClipRayToEntity( const Ray_t &ray , unsigned int fMask , IHandleEntity *pEnt , trace_t *pTrace ) = 0;
		virtual void	ClipRayToCollideable( const Ray_t &ray , unsigned int fMask , ICollideable *pCollide , trace_t *pTrace ) = 0;
		
		void TraceRay( const Ray_t &ray , unsigned int fMask , ITraceFilter *pTraceFilter , trace_t *pTrace )
		{
			VirtualFn( void )( PVOID , const Ray_t &, unsigned int, ITraceFilter *, trace_t * );
			GetVMethod<OriginalFn>( this , 5 )( this , ray , fMask , pTraceFilter , pTrace );
		}

		virtual void	SetupLeafAndEntityListRay( const Ray_t &ray , ITraceListData *pTraceData ) = 0;
		virtual void    SetupLeafAndEntityListBox( const Vector &vecBoxMin , const Vector &vecBoxMax , ITraceListData *pTraceData ) = 0;
		virtual void	TraceRayAgainstLeafAndEntityList( const Ray_t &ray , ITraceListData *pTraceData , unsigned int fMask , ITraceFilter *pTraceFilter , trace_t *pTrace ) = 0;
		virtual void	SweepCollideable( ICollideable *pCollide , const Vector &vecAbsStart , const Vector &vecAbsEnd ,
										  const QAngle &vecAngles , unsigned int fMask , ITraceFilter *pTraceFilter , trace_t *pTrace ) = 0;
		virtual void	EnumerateEntities( const Ray_t &ray , bool triggers , IEntityEnumerator *pEnumerator ) = 0;
		virtual void	EnumerateEntities( const Vector &vecAbsMins , const Vector &vecAbsMaxs , IEntityEnumerator *pEnumerator ) = 0;
		virtual ICollideable *GetCollideable( IHandleEntity *pEntity ) = 0;
		virtual int GetStatByIndex( int index , bool bClear ) = 0;
		virtual void GetBrushesInAABB( const Vector &vMins , const Vector &vMaxs , CUtlVector<int> *pOutput , int iContentsMask = 0xFFFFFFFF ) = 0;
		virtual CPhysCollide* GetCollidableFromDisplacementsInAABB( const Vector& vMins , const Vector& vMaxs ) = 0;
		virtual int GetNumDisplacements() = 0;
		virtual void GetDisplacementMesh( int nIndex , virtualmeshlist_t *pMeshTriList ) = 0;
		virtual bool GetBrushInfo( int iBrush , CUtlVector<BrushSideInfo_t> *pBrushSideInfoOut , int *pContentsOut ) = 0;
		virtual bool PointOutsideWorld( const Vector &ptTest ) = 0;
		virtual int GetLeafContainingPoint( const Vector &ptTest ) = 0;
		virtual ITraceListData *AllocTraceListData() = 0;
		virtual void FreeTraceListData( ITraceListData * ) = 0;
		virtual int GetSetDebugTraceCounter( int value , DebugTraceCounterBehavior_t behavior ) = 0;
	};
}