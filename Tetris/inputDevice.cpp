#include "inputDevice.h"

InputDevice::InputDevice() {
    milliseconds requiredDelayMillis(250);
    lastDropFaster = high_resolution_clock::now() - requiredDelayMillis;
    lastDropOnce = high_resolution_clock::now() - requiredDelayMillis;
    lastRotateLeft = high_resolution_clock::now() - requiredDelayMillis;
    lastRotateRight = high_resolution_clock::now() - requiredDelayMillis;
    lastTranslateLeft = high_resolution_clock::now() - requiredDelayMillis;
    lastTranslateRight = high_resolution_clock::now() - requiredDelayMillis;
}

bool InputDevice::translateLeft()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastTranslateLeft).count() > 250 && KeyboardInput::translateLeft()) {
        lastTranslateLeft = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::translateRight()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastTranslateRight).count() > 250 && KeyboardInput::translateRight()) {
        lastTranslateRight = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::rotateRight()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastRotateRight).count() > 250 && KeyboardInput::rotateRight()) {
        lastRotateRight = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::rotateLeft()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastRotateLeft).count() > 250 && KeyboardInput::rotateLeft()) {
        lastRotateLeft = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::dropFaster()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastDropFaster).count() > 250 && KeyboardInput::dropFaster()) {
        lastDropFaster = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::dropOnce()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastDropOnce).count() > 250 && KeyboardInput::dropOnce()) {
        lastDropOnce = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}
