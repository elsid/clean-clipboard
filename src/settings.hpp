#include <vector>

#include "types.hpp"

struct Settings {
    unsigned checkKeyboardTimeout;
    unsigned cleanTimeout;
    std::vector<Key> keysCombination;

    Settings(const unsigned checkKeyboardTimeout, const unsigned cleanTimeout,
            std::vector<Key> &&keysCombination);
};

Settings parseSettings(const std::string &text);
