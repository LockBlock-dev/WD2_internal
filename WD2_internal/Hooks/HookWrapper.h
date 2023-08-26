#pragma once
#include <Windows.h>
#include <string>


class HookWrapper
{
private:
	bool installed = false;
	bool enabled = false;
	LPVOID targetFunc = nullptr;
	LPVOID detourFunc = nullptr;
	LPVOID* originalFunc = nullptr;
protected:
	std::string _name;
public:
	HookWrapper();
	std::string& name();
	const std::string& name() const;
	HookWrapper* setTargetFunc(LPVOID targetFunc);
	HookWrapper* setDetourFunc(LPVOID detourFunc);
	HookWrapper* setOriginalFunc(LPVOID originalFunc);
	bool install();
	bool remove();
	bool enable();
	bool disable();
};
