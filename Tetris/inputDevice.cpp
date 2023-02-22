#include "inputDevice.h"

bool InputDevice::translateLeft()
{
    return KeyboardInput::translateLeft();
}

bool InputDevice::translateRight()
{
    return KeyboardInput::translateRight();
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
