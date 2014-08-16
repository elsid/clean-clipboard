#include "errors.hpp"
#include "keys.hpp"

Key getKeyCode(const std::string &name) {
    const auto it = keys.find(name);
    if (it == keys.end()) {
        throw KeyNameError(name);
    }
    return it->second;
}
