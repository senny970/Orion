#pragma once

namespace SDK
{
	struct SpatializationInfo_t;

	class IClientEntity :
    public IClientUnknown,
    public IClientRenderable,
    public IClientNetworkable,
    public IClientThinkable
	{
	public:

		virtual void Release( void ) = 0;
		virtual const Vector GetAbsOrigin( void ) const = 0;
		virtual const Vector GetAbsAngles( void ) const = 0;
		virtual void* GetMouth( void ) = 0;
		virtual bool GetSoundSpatialization( SpatializationInfo_t info ) = 0;
		virtual bool IsBlurred( void ) = 0;
	};
}