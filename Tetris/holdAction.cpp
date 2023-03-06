#include "holdAction.h"

HoldAction::HoldAction(bool(*assingKeyboardDelegate)(), bool(*assingControllerDelegate)(), int assingInputDelay) : Action(assingKeyboardDelegate, assingControllerDelegate), inputDelay(assingInputDelay)
{
	wasPressed = false;
	milliseconds requiredDelayMillis(inputDelay);
	lastActivation = high_resolution_clock::now() - requiredDelayMillis;
}

bool HoldAction::isActivated()
{
	return false;
}
