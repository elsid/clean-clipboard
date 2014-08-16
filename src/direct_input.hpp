#ifndef DIRECT_INPUT_HPP
#define DIRECT_INPUT_HPP

#include <dinput.h>

#include "types.hpp"

class DirectInputKeyboard;

class DirectInput {
public:
    DirectInput(HINSTANCE instance);
    DirectInput(const DirectInput &) = delete;
    DirectInput(DirectInput &&) = default;
    DirectInputKeyboard createKeyboard();

private:
    IDirectInput8Ptr input;
};

#endif
