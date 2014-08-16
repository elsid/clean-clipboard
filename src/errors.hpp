#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <stdexcept>

#include <windows.h>

struct DirectInput8CreateError : public std::runtime_error {
    DirectInput8CreateError(const HRESULT result)
        : std::runtime_error("DirectInputCreate8 error code: "
                             + std::to_string(result)) {}
};

struct IDirectInput8CreateDeviceError : public std::runtime_error {
    IDirectInput8CreateDeviceError(const HRESULT result)
        : std::runtime_error("IDirectInput8::CreateDevice error code: "
                             + std::to_string(result)) {}
};

struct IDirectInputDevice8AcquireError : public std::runtime_error {
    IDirectInputDevice8AcquireError(const HRESULT result)
        : std::runtime_error("IDirectInputDevice8::Acquire error code: "
                             + std::to_string(result)) {}
};

struct IDirectInputDevice8SetDataFormatError : public std::runtime_error {
    IDirectInputDevice8SetDataFormatError(const HRESULT result)
        : std::runtime_error("IDirectInputDevice8::SetDataFormat error code: "
                             + std::to_string(result)) {}
};

struct IDirectInputDevice8GetDeviceStateError : public std::runtime_error {
    IDirectInputDevice8GetDeviceStateError(const HRESULT result)
        : std::runtime_error("IDirectInputDevice8::GetDeviceState error code: "
                             + std::to_string(result)) {}
};

struct ClipboardError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct OpenClipboardError : public ClipboardError {
    OpenClipboardError(const DWORD error)
        : ClipboardError("OpenClipboard Windows error code: "
                         + std::to_string(error)) {}
};

struct EmptyClipboardError : public ClipboardError {
    EmptyClipboardError(const DWORD error)
        : ClipboardError("EmptyClipboard Windows error code: "
                         + std::to_string(error)) {}
};

struct KeyNameError : public std::runtime_error {
    KeyNameError(const std::string &name)
        : std::runtime_error("Key name error: " + name) {}
};

struct ParseSettingsError : public std::runtime_error {
    ParseSettingsError(const std::string &message)
        : std::runtime_error(message) {}
};

struct ParseCheckKeyboardTimeoutError : public ParseSettingsError {
    ParseCheckKeyboardTimeoutError()
        : ParseSettingsError("Error parse check keyboard timeout") {}
};

struct ParseCleanTimeoutError : public ParseSettingsError {
    ParseCleanTimeoutError()
        : ParseSettingsError("Error parse clean timeout") {}
};

#endif
