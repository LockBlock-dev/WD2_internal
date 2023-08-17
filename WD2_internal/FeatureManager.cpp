#include "FeatureManager.h"
#include "Features/Money.h"
#include "Features/RP.h"


FeatureManager::FeatureManager()
{
    std::shared_ptr<Money> money = std::make_shared<Money>();
    std::shared_ptr<RP> rp = std::make_shared<RP>();

    features[money->name()] = money;
    features[rp->name()] = rp;
}

FeatureManager& FeatureManager::getInstance()
{
    static FeatureManager instance;

    return instance;
}

FeaturesMap FeatureManager::getFeatures()
{
    return features;
}

ToggleableFeaturesMap FeatureManager::getToggleableFeatures()
{
    ToggleableFeaturesMap toggleableFeatures;

    for (auto const& [name, feature] : features)
    {
        std::shared_ptr<ToggleFeature> toggleFeature = std::dynamic_pointer_cast<ToggleFeature>(feature);
        if (toggleFeature != nullptr)
        {
            toggleableFeatures[name] = toggleFeature;
        }
    }

    return toggleableFeatures;
}
