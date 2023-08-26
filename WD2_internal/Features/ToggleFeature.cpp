#include "ToggleFeature.h"


void ToggleFeature::enable()
{
	this->enabled = true;
}

void ToggleFeature::disable()
{
	this->enabled = false;
}

void ToggleFeature::update()
{
	this->enabled ? this->updateWhenEnabled() : this->updateWhenDisabled();
}
