#include "Money.h"
#include "../Memory.h"
#include "../Context.h"
#include <iostream>


Money::Money()
{
	this->_name = "Money";
}

void Money::updateWhenEnabled()
{
	try {
		uintptr_t balanceAddr = Memory::getAddress(Context::moduleBase + 0x3FAEAA8, { 0x728 });

		if (balanceAddr)
		{
			// int balance = Memory::read<int>(balanceAddr);

			Memory::write<int>(balanceAddr, 1'000'000'000);
		}
	}
	catch (...)
	{
		std::cerr << "[Feature: Money] Error\n";
	}
}

void Money::updateWhenDisabled() {}
