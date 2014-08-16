#include <iostream>

#include "errors.hpp"
#include "direct_input.hpp"
#include "direct_input_keyboard.hpp"

namespace {

IDirectInputDevice8Ptr createKeyboard(IDirectInput8Ptr input) {
    IDirectInputDevice8 *device;
    const auto result = input->CreateDevice(GUID_SysKeyboard, &device, nullptr);
    if (result != DI_OK) {
        throw IDirectInput8CreateDeviceError(result);
    }
    return IDirectInputDevice8Ptr(device,
        [] (IDirectInputDevice8 *device) { device->Release(); });
}

}

DirectInputKeyboard::DirectInputKeyboard(IDirectInput8Ptr input) :
        device(createKeyboard(input)) {
    const auto setDataFormatResult = device->SetDataFormat(&c_dfDIKeyboard);
    if (setDataFormatResult != DI_OK) {
        throw IDirectInputDevice8SetDataFormatError(setDataFormatResult);
    }
    const auto acquireResult = device->Acquire();
    if (acquireResult != DI_OK) {
        throw IDirectInputDevice8AcquireError(acquireResult);
    }
}

DirectInputKeyboard::~DirectInputKeyboard() {
    const auto result = device->Unacquire();
    if (result != DI_OK) {
        std::cerr << "IDirectInputDevice8::Unacquire error: " << result
                  << std::endl;
    }
}

DirectInputKeyboardState DirectInputKeyboard::getState() const {
    DirectInputKeyboardState::Data stateData;
    const auto result = device->GetDeviceState(stateData.size(),
        reinterpret_cast<LPVOID>(stateData.data()));
    if (result != DI_OK) {
        throw IDirectInputDevice8GetDeviceStateError(result);
    }
    return DirectInputKeyboardState(std::move(stateData));
}
