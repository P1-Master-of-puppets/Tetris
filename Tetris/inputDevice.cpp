#include "inputDevice.h"

InputDevice::InputDevice() {
    milliseconds requiredDelayMillis(inputDelay);
    lastDropFaster = high_resolution_clock::now() - requiredDelayMillis;
    lastDropOnce = high_resolution_clock::now() - requiredDelayMillis;
    lastRotateLeft = high_resolution_clock::now() - requiredDelayMillis;
    lastRotateRight = high_resolution_clock::now() - requiredDelayMillis;
    lastTranslateLeft = high_resolution_clock::now() - requiredDelayMillis;
    lastTranslateRight = high_resolution_clock::now() - requiredDelayMillis;
}

bool InputDevice::translateLeft()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastTranslateLeft).count() > inputDelay && KeyboardInput::translateLeft()) {
        lastTranslateLeft = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::translateRight()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastTranslateRight).count() > inputDelay && KeyboardInput::translateRight()) {
        lastTranslateRight = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::rotateRight()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastRotateRight).count() > inputDelay && KeyboardInput::rotateRight()) {
        lastRotateRight = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::rotateLeft()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastRotateLeft).count() > inputDelay && KeyboardInput::rotateLeft()) {
        lastRotateLeft = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::dropFaster()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastDropFaster).count() > inputDelay && KeyboardInput::dropFaster()) {
        lastDropFaster = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}

bool InputDevice::dropOnce()
{
    if (duration_cast<milliseconds>(high_resolution_clock::now() - lastDropOnce).count() > inputDelay && KeyboardInput::dropOnce()) {
        lastDropOnce = high_resolution_clock::now();
        return true;
    }
    else {
        return false;
    }
}
