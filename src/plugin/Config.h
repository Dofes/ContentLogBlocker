#pragma once

#include "ll/api/reflection/Dispatcher.h"

#include "PairHash.h"
#include <unordered_set>

namespace blocker {
using ll::reflection::Dispatcher;
struct Config {
    int                                                version = 0;
    std::unordered_set<std::pair<int, int>, pair_hash> blocked{
        {3, 29}, // Error Structure
        {3, 26}, // Error Script
        {3, 9 }  // Error Component
    };
};

} // namespace blocker