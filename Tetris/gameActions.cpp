#include "gameActions.h"

void GameActions::initKeyboardSettings()
{
	translateLeftAction.addInput(new Input(_keyboard, &Control::getJoystickLeft));
	translateRightAction.addInput(new Input(_keyboard, &Control::getJoyStickRight));
	rotateLeftAction.addInput(new Input(_keyboard, &Control::getLeftTrigger));
	rotateRightAction.addInput(new Input(_keyboard, &Control::getRightTrigger));
	dropFasterAction.addInput(new Input(_keyboard, &Control::getAButton));
	dropInstantAction.addInput(new Input(_keyboard, &Control::getJoyStickButton));
	menuAction.addInput(new Input(_keyboard, &Control::getMenuButton));
}

GameActions::GameActions(Controller* controller, Keyboard* keyboard)
{
	_controller = controller;
	_keyboard = keyboard;
	initKeyboardSettings();
}

GameActions::GameActions(Keyboard* keyboard)
{
	_controller = nullptr;
	_keyboard = keyboard;
	initKeyboardSettings();
}

GameActions::~GameActions()
{
}

bool GameActions::translateLeft()
{
	return translateLeftAction.isActive();
}

bool GameActions::translateRight()
{
	return translateRightAction.isActive();
}

bool GameActions::rotateRight()
{
	return rotateRightAction.isActive();
}

bool GameActions::rotateLeft()
{
	return rotateLeftAction.isActive();
}

bool GameActions::dropFaster()
{
	return dropFasterAction.isActive();
}

bool GameActions::dropInstant()
{
	return dropInstantAction.isActive();
}

bool GameActions::menu()
{
	return menuAction.isActive();
}

void GameActions::loadSettings(Setting setting)
{
	if (_controller == nullptr)
		return;

}