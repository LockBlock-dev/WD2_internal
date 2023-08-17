#pragma once
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include "Features/Feature.h"
#include "Features/ToggleFeature.h"


typedef std::map<std::string, std::shared_ptr<Feature>> FeaturesMap;
typedef std::map<std::string, std::shared_ptr<ToggleFeature>> ToggleableFeaturesMap;


class FeatureManager
{
private:
    FeatureManager();
    FeaturesMap features{};
public:
    static FeatureManager& getInstance();
    FeaturesMap getFeatures();
    ToggleableFeaturesMap getToggleableFeatures();
};
