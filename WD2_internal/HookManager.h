#pragma once
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include "Hooks/HookWrapper.h"


typedef std::map<std::string, std::shared_ptr<HookWrapper>> HooksMap;


class HookManager
{
private:
    HookManager();
    HooksMap hooks{};
public:
    static HookManager& getInstance();
    HooksMap getHooks();
    void enableAll();
    void disableAll();
};
