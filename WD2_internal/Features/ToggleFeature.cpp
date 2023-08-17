#include "ToggleFeature.h"


void ToggleFeature::enable()
{
	enabled = true;
}

void ToggleFeature::disable()
{
	enabled = false;
}

void ToggleFeature::update()
{
	enabled ? updateWhenEnabled() : updateWhenDisabled();
}
