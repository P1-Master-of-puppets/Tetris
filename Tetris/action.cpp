#include "action.h"

Action::Action(bool(*assingKeyboardDelegate)(), bool(*assingControllerDelegate)()) : keyboardDelegate(assingKeyboardDelegate), controllerDelegate(assingControllerDelegate)
{
	wasPressed = false;
}

bool Action::isActivated()
{
	if (!wasPressed && (keyboardDelegate() || controllerDelegate())) {
		wasPressed = true;
		return true;
	}


	if (wasPressed && !keyboardDelegate() && !controllerDelegate()) {
		wasPressed = false;
	}

	return false;
}
