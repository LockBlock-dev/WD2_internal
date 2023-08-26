#include "InfiniteBotnets.h"
#include "../Memory.h"
#include "../Context.h"
#include <iostream>


typedef void(__fastcall* sub_1853B1002)(uintptr_t a1, unsigned int a2);

// Pointer to original
sub_1853B1002 sub_1853B1002_original = nullptr;
sub_1853B1002 sub_1853B1002_target = nullptr;

void __fastcall Detour(uintptr_t a1, unsigned int newBotnets)
{
	try
	{
		uintptr_t playerAddr = Memory::getAddress(Context::moduleBase + 0x3FD90C8, { 0x0, 0x648 });

		if (playerAddr)
		{
			uintptr_t playerPtr = Memory::read<uintptr_t>(playerAddr);

			if (playerPtr && a1 == playerPtr)
			{
				return sub_1853B1002_original(a1, 20);
			}
		}
	}
	catch (...)
	{
		//
	}

	// If something went wrong
	return sub_1853B1002_original(a1, newBotnets);
}

InfiniteBotnets::InfiniteBotnets()
{
	this->_name = "InfiniteBotnet";

	uintptr_t sub_1853B1002_addr = Memory::getAddress(Context::moduleBase + 0x53B1002);
	sub_1853B1002_target = reinterpret_cast<sub_1853B1002>(sub_1853B1002_addr);

	this->setTargetFunc(sub_1853B1002_target)
		->setDetourFunc(&Detour)
		->setOriginalFunc(&sub_1853B1002_original);
}
