#pragma once
#include "Feature.h"


class ToggleFeature : public Feature
{
private:
	bool enabled = false;
protected:
	virtual void updateWhenEnabled() PURE;
	virtual void updateWhenDisabled() PURE;
public:
	void enable();
	void disable();
	void update() override;
};
