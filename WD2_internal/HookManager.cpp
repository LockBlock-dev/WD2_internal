#include "HookManager.h"
#include "Hooks/GodMode.h"
#include "Hooks/InfiniteBotnets.h"

HookManager::HookManager()
{
    std::shared_ptr<GodMode> godMode = std::make_shared<GodMode>();
    std::shared_ptr<InfiniteBotnets> infiniteBotnets = std::make_shared<InfiniteBotnets>();

    this->hooks[godMode->name()] = godMode;
    this->hooks[infiniteBotnets->name()] = infiniteBotnets;
}

HookManager& HookManager::getInstance()
{
    static HookManager instance;

    return instance;
}

HooksMap HookManager::getHooks()
{
    return this->hooks;
}

void HookManager::enableAll()
{
    for (auto const& [name, hook] : this->hooks)
    {
        hook->enable();
    }
}

void HookManager::disableAll()
{
    for (auto const& [name, hook] : this->hooks)
    {
        hook->disable();
    }
}
