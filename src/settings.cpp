#include <sstream>

#include "errors.hpp"
#include "keys.hpp"
#include "settings.hpp"

Settings::Settings(const unsigned checkKeyboardTimeout,
        const unsigned cleanTimeout, std::vector<Key> &&keysCombination)
        : checkKeyboardTimeout(checkKeyboardTimeout)
        , cleanTimeout(cleanTimeout)
        , keysCombination(std::move(keysCombination)) {}

namespace {

unsigned parseCheckKeyboardTimeout(std::istream &stream) {
    unsigned checkKeyboardTimeout;
    if (!(stream >> checkKeyboardTimeout)) {
        throw ParseCheckKeyboardTimeoutError();
    }
    return checkKeyboardTimeout;
}

unsigned parseCleanTimeout(std::istream &stream) {
    unsigned cleanTimeout;
    if (!(stream >> cleanTimeout)) {
        throw ParseCleanTimeoutError();
    }
    return cleanTimeout;
}

std::vector<Key> parseKeysCombination(std::istream &stream) {
    std::vector<Key> keysCombination;
    std::string key;
    while (stream >> key) {
        keysCombination.push_back(getKeyCode(key));
    }
    return keysCombination;
}

}

Settings parseSettings(const std::string &text) {
    std::stringstream stream(text);
    const auto checkKeyboardTimeout = parseCheckKeyboardTimeout(stream);
    const auto cleanTimeout = parseCleanTimeout(stream);
    auto keysCombination = parseKeysCombination(stream);
    return Settings(checkKeyboardTimeout, cleanTimeout,
        std::move(keysCombination));
}
