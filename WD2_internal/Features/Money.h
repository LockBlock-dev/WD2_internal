#pragma once
#include "ToggleFeature.h"


class Money : public ToggleFeature
{
protected:
	void updateWhenEnabled() override;
	void updateWhenDisabled() override;
public:
	Money();
};
