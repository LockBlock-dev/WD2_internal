#include "GodMode.h"
#include "../Memory.h"
#include "../Context.h"


typedef void(__fastcall* sub_186962B31)(
	uintptr_t a1, float newHealth, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, int a11, int a12
);

// Pointer to original
sub_186962B31 sub_186962B31_original = nullptr;
sub_186962B31 sub_186962B31_target = nullptr;

void __fastcall Detour(
	uintptr_t a1, float newHealth, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, int a11, int a12
)
{
	try
	{
		uintptr_t playerAddr = Memory::getAddress(Context::moduleBase + 0x3FD90C8, { 0x0, 0x640, 0xA8 });

		if (playerAddr)
		{
			uintptr_t playerPtr = Memory::read<uintptr_t>(playerAddr);

			if (playerPtr && a1 == playerPtr)
			{
				return sub_186962B31_original(a1, 100.0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
			}
		}
	}
	catch (...)
	{
		//
	}
	
	// If something went wrong or if the entity is not the player
	return sub_186962B31_original(a1, newHealth, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

GodMode::GodMode()
{
	this->_name = "GodMode";

	uintptr_t sub_186962B31_addr = Memory::getAddress(Context::moduleBase + 0x6962B31);
	sub_186962B31_target = reinterpret_cast<sub_186962B31>(sub_186962B31_addr);

	this->setTargetFunc(sub_186962B31_target)
		->setDetourFunc(&Detour)
		->setOriginalFunc(&sub_186962B31_original);
}
