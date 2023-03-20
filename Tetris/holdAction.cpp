#include "holdAction.h"

HoldAction::HoldAction()
{
	interval = 200;
    lastInput = high_resolution_clock::now() - milliseconds(interval);
}

HoldAction::HoldAction(int setInterval) : interval(setInterval)
{
    lastInput = high_resolution_clock::now() - milliseconds(interval);
}

HoldAction::~HoldAction()
{
}

bool HoldAction::isActive()
{
    if (getCurrentState() && !lastButtonState) {
        lastButtonState = true;
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (getCurrentState() && lastButtonState && 
        milliseconds(interval) < high_resolution_clock::now() - lastInput ) {
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (!getCurrentState() && lastButtonState) {
        lastButtonState = false;
    }

    return false;
}
