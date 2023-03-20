#include "gameActions.h"

GameActions::GameActions()
{
	translateLeftAction.addInput(KeyboardInput::translateLeft);
	translateRightAction.addInput(KeyboardInput::translateRight);
	rotateLeftAction.addInput(KeyboardInput::rotateLeft);
	rotateRightAction.addInput(KeyboardInput::rotateRight);
	dropFasterAction.addInput(KeyboardInput::dropFaster);
	dropInstantAction.addInput(KeyboardInput::dropFaster);
	menuAction.addInput(KeyboardInput::menu);
	holdPieceAction.addInput(KeyboardInput::holdPiece);
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

bool GameActions::holdPiece()
{
	return holdPieceAction.isActive();
}

void GameActions::loadSettings(InputSetting newSetting)
{

}