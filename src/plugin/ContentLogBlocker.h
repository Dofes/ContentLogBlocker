#pragma once

#include "ll/api/plugin/NativePlugin.h"
#include "plugin/Config.h"

namespace blocker {

class ContentLogBlocker {

public:
    static ContentLogBlocker& getInstance();

    ContentLogBlocker(ll::plugin::NativePlugin& self) : mSelf(self) {}

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const { return mSelf; }

    bool load();

    bool enable();

    bool disable();

    bool loadConfig();

    bool saveConfig();

    Config& getConfig();

    std::filesystem::path getConfigPath() const;

private:
    ll::plugin::NativePlugin& mSelf;
    Config                    mConfig;
};

} // namespace blocker
