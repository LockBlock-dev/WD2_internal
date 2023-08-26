#include "Feature.h"


std::string& Feature::name()
{
	return this->_name;
}

const std::string& Feature::name() const
{
	return this->_name;
}
