#pragma once
#include "ToggleFeature.h"


class NoReload : public ToggleFeature
{
protected:
	void updateWhenEnabled() override;
	void updateWhenDisabled() override;
public:
	NoReload();
};
