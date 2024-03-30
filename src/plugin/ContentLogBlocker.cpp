#include "plugin/ContentLogBlocker.h"

#include <memory>

#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"

#include "ll/api/Config.h"
#include "ll/api/utils/ErrorUtils.h"

#include "Config.h"

namespace blocker {

static std::unique_ptr<ContentLogBlocker> instance;

ll::Logger logger("ContentLogBlocker");

std::filesystem::path ContentLogBlocker::getConfigPath() const { return getSelf().getConfigDir() / u8"config.json"; }

bool ContentLogBlocker::loadConfig() {
    bool res{};
    try {
        res = ll::config::loadConfig(mConfig, getConfigPath());
    } catch (...) {
        ll::error_utils::printCurrentException(logger);
        res = false;
    }
    if (!res) {
        res = ll::config::saveConfig(mConfig, getConfigPath());
    }
    return res;
}

bool ContentLogBlocker::saveConfig() { return ll::config::saveConfig(mConfig, getConfigPath()); }

ContentLogBlocker& ContentLogBlocker::getInstance() { return *instance; }

Config& ContentLogBlocker::getConfig() { return mConfig; }

bool ContentLogBlocker::load() { return true; }

bool ContentLogBlocker::enable() {
    if (!loadConfig()) {
        return false;
    }

    return true;
}

bool ContentLogBlocker::disable() {
    saveConfig();
    return true;
}

} // namespace blocker

LL_REGISTER_PLUGIN(blocker::ContentLogBlocker, blocker::instance);


#include "mc/deps/core/debug/log/ContentLog.h"


#include "ll/api/memory/Hook.h"

LL_AUTO_TYPE_INSTANCE_HOOK(
    ContentLogBlock,
    ll::memory::HookPriority::Normal,
    ContentLog,
    &ContentLog::log,
    void,
    bool       logOnlyOnce,
    ::LogLevel level,
    ::LogArea  area,
    ...
) {
    auto config = blocker::ContentLogBlocker::getInstance().getConfig();
    if (config.blocked.find({(int)level, (int)area}) != config.blocked.end()) return;
    origin(logOnlyOnce, level, area);
}