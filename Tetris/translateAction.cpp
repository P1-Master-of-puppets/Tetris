#include "translateAction.h"

TranslateAction::TranslateAction() : HoldAction(200)
{
    initialInterval = 750;
    lastInput = high_resolution_clock::now() - milliseconds(initialInterval);
    initialPress = true;
}

TranslateAction::TranslateAction(int setInitialInterval, int setInterval): HoldAction(setInterval), initialInterval(setInitialInterval)
{
    initialPress = true;
    lastInput = high_resolution_clock::now() - milliseconds(initialInterval);
}

TranslateAction::~TranslateAction()
{
}

bool TranslateAction::isActive()
{
    if (getCurrentState() && !lastButtonState) {
        lastButtonState = true;
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (getCurrentState() && lastButtonState &&
        milliseconds(initialInterval) < high_resolution_clock::now() - lastInput &&
        initialPress) {
        lastInput = high_resolution_clock::now();
        initialPress = false;
        return true;
    }
    else if (getCurrentState() && lastButtonState &&
             milliseconds(interval) < high_resolution_clock::now() - lastInput &&
             !initialPress) {
        lastInput = high_resolution_clock::now();
        return true;
    }

    if (!getCurrentState() && lastButtonState) {
        initialPress = true;
        lastButtonState = false;
    }

    return false;
}
