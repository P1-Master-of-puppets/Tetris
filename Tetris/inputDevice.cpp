#include "inputDevice.h"

bool InputDevice::left()
{
    return KeyboardInput::left();
}

bool InputDevice::right()
{
    return KeyboardInput::right();
}

bool InputDevice::rotateRight()
{
    return KeyboardInput::rotateRight();
}

bool InputDevice::rotateLeft()
{
    return KeyboardInput::rotateLeft();
}

bool InputDevice::dropFaster()
{
    return KeyboardInput::dropFaster();
}

bool InputDevice::dropOnce()
{
    return KeyboardInput::dropOnce();
}
