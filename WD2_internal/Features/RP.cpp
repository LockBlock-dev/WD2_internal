#include "RP.h"
#include "../Memory.h"
#include "../Context.h"
#include <iostream>


RP::RP()
{
	this->_name = "RP";
}

void RP::updateWhenEnabled()
{
	try {
		uintptr_t RPAddr = Memory::getAddress(Context::moduleBase + 0x3F95808, { 0x4A4 });

		if (RPAddr)
		{
			// int RP = Memory::read<int>(RPAddr);

			Memory::write<int>(RPAddr, 100);
		}
	}
	catch (...)
	{
		std::cerr << "[Feature: RP] Error\n";
	}
}

void RP::updateWhenDisabled() {}
