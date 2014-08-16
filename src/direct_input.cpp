#include "errors.hpp"
#include "direct_input.hpp"
#include "direct_input_keyboard.hpp"

namespace {

IDirectInput8Ptr createInput(HINSTANCE instance) {
    IDirectInput8 *input;
    const auto result = DirectInput8Create(instance, DIRECTINPUT_VERSION,
        IID_IDirectInput8, reinterpret_cast<LPVOID *>(&input), 0);
    if (result != DI_OK) {
        throw DirectInput8CreateError(result);
    }
    return IDirectInput8Ptr(input,
        [] (IDirectInput8 *input) { input->Release(); });
}

}

DirectInput::DirectInput(HINSTANCE instance) : input(createInput(instance)) {}

DirectInputKeyboard DirectInput::createKeyboard() {
    return DirectInputKeyboard(input);
}
