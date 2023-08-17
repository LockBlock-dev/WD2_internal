#pragma once
#include "ToggleFeature.h"


class RP : public ToggleFeature
{
protected:
	void updateWhenEnabled() override;
	void updateWhenDisabled() override;
public:
	RP();
};
