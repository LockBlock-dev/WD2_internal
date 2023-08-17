#pragma once
#include <Windows.h>
#include <string>


class Feature
{
protected:
	std::string _name;
public:
    std::string& name();
    const std::string& name() const;

    virtual void update() PURE;
};
