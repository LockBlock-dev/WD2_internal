#pragma once
#include <Windows.h>

namespace Context
{
	inline uintptr_t moduleBase = reinterpret_cast<uintptr_t>(GetModuleHandleW(L"Disrupt_64.dll"));
}
