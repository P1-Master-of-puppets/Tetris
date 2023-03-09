#ifndef GAME_ACTIONS_H__
#define GAME_ACTIONS_H__

#include <chrono>
#include "keyboardInput.h"
#include "controllerInput.h"
#include "action.h"

using namespace std::chrono;

class GameActions
{
public:
	GameActions();
	bool translateLeft();
	bool translateRight();
	bool rotateRight();
	bool rotateLeft();
	bool dropFaster();
	bool dropOnce();
private:
	Action tLeft();
};

#endif