#include "singleInputAction.h"

SingleInputAction::SingleInputAction()
{
}

SingleInputAction::~SingleInputAction()
{
}

bool SingleInputAction::isActive()
{
    if (getCurrentState() && !lastButtonState) {
        lastButtonState = true;
        return true;
    }

    if (!getCurrentState() && lastButtonState) {
        lastButtonState = false;
    }

    return false;
}
