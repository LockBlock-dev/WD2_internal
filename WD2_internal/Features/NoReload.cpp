#include "NoReload.h"
#include "../Memory.h"
#include "../Context.h"
#include <iostream>


NoReload::NoReload()
{
	this->_name = "NoReload";
}

void NoReload::updateWhenEnabled()
{
	try {
		uintptr_t decrementClipInstructionAddr = Memory::getAddress(Context::moduleBase + 0x56FD911);

		if (decrementClipInstructionAddr)
		{
			Memory::nop(reinterpret_cast<BYTE*>(decrementClipInstructionAddr), 6);
		}
	}
	catch (...)
	{
		std::cerr << "[Feature: NoReload] Error\n";
	}
}

void NoReload::updateWhenDisabled() {
	try {
		uintptr_t decrementClipInstructionAddr = Memory::getAddress(Context::moduleBase + 0x56FD911);

		if (decrementClipInstructionAddr)
		{
			std::vector<BYTE> original = {0xFF, 0x8B, 0xA8, 0x00, 0x00, 0x00};
			Memory::patch(reinterpret_cast<BYTE*>(decrementClipInstructionAddr), original.data(), original.size());
		}
	}
	catch (...)
	{
		std::cerr << "[Feature: NoReload] Error\n";
	}
}
