#ifndef DIRECT_INPUT_KEYBOARD_HPP
#define DIRECT_INPUT_KEYBOARD_HPP

#include <algorithm>

#include <dinput.h>

#include "types.hpp"

class DirectInputKeyboardState {
public:
    static constexpr int keyDownFlag = 0x80;
    static constexpr std::size_t keysCount = 256;

    using Data = std::array<char, keysCount>;

    DirectInputKeyboardState(const Data &data) : data(data) {}
    DirectInputKeyboardState(Data &&data) : data(data) {}
    bool isKeyDown(const Key key) const { return data[key] & keyDownFlag; }

    template <typename Container>
    bool isKeysDown(const Container &keys) const {
        const auto end = std::end(keys);
        return end == std::find_if_not(std::begin(keys), end,
            [this] (const Key key) { return isKeyDown(key); });
    }

private:
    Data data;
};

class DirectInputKeyboard {
public:
    DirectInputKeyboard(IDirectInput8Ptr input);
    DirectInputKeyboard(const DirectInputKeyboard &) = delete;
    DirectInputKeyboard(DirectInputKeyboard &&) = default;
    virtual ~DirectInputKeyboard();
    DirectInputKeyboardState getState() const;

private:
    IDirectInputDevice8Ptr device;
};

#endif
