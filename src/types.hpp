#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>

#include <dinput.h>

using IDirectInput8Ptr = std::shared_ptr<IDirectInput8>;
using IDirectInputDevice8Ptr = std::shared_ptr<IDirectInputDevice8>;
using Key = unsigned char;

#endif
