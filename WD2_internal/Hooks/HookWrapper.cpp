#include "HookWrapper.h"
#include "../Dependencies/minhook/include/MinHook.h"


HookWrapper::HookWrapper() {};

std::string& HookWrapper::name()
{
	return this->_name;
}

const std::string& HookWrapper::name() const
{
	return this->_name;
}

HookWrapper* HookWrapper::setTargetFunc(LPVOID targetFunc)
{
	this->targetFunc = targetFunc;

	return this;
}

HookWrapper* HookWrapper::setDetourFunc(LPVOID detourFunc)
{
	this->detourFunc = detourFunc;

	return this;
}

HookWrapper* HookWrapper::setOriginalFunc(LPVOID originalFunc)
{
	this->originalFunc = reinterpret_cast<LPVOID*>(originalFunc);

	return this;
}

bool HookWrapper::install()
{
	if (
		this->enabled
		|| this->installed
		|| this->targetFunc == nullptr
		|| this->detourFunc == nullptr
		|| this->originalFunc == nullptr
	) return false;

	MH_STATUS status = MH_CreateHook(this->targetFunc, this->detourFunc, this->originalFunc);

	if (status == MH_OK)
	{
		this->installed = true;
	}

	return this->installed;
}

bool HookWrapper::remove()
{
	if (!this->installed) return false;

	MH_STATUS status = MH_RemoveHook(this->targetFunc);

	if (status == MH_OK)
	{
		this->installed = false;
	}

	return !this->installed;
}

bool HookWrapper::enable()
{
	if (this->enabled) return false;

	MH_STATUS status = MH_EnableHook(this->targetFunc);

	if (status == MH_ERROR_NOT_CREATED)
	{
		if (this->install())
		{
			status = MH_EnableHook(this->targetFunc);
		}
	}

	if (status == MH_OK)
	{
		this->enabled = true;
	}

	return this->enabled;
}

bool HookWrapper::disable()
{
	if (!this->enabled) return false;

	MH_STATUS status = MH_DisableHook(this->targetFunc);

	if (status == MH_OK)
	{
		this->enabled = false;
	}

	return !this->enabled;
}
