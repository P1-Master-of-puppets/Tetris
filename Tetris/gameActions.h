#ifndef GAME_ACTIONS_H__
#define GAME_ACTIONS_H__

#include <chrono>
#include "keyboardInput.h"
#include "action.h"
#include "holdAction.h"
#include "singleInputAction.h"
#include "translateAction.h"
#include "setting.h"

using namespace std::chrono;

class GameActions
{
public:
	GameActions();
	~GameActions();
	bool translateLeft();
	bool translateRight();
	bool rotateRight();
	bool rotateLeft();
	bool dropFaster();
	bool dropInstant();
	bool menu();
	void loadSettings(Setting setting);
private:
	TranslateAction translateLeftAction;
	TranslateAction translateRightAction;
	SingleInputAction rotateRightAction;
	SingleInputAction rotateLeftAction;
	SingleInputAction dropFasterAction;
	SingleInputAction dropInstantAction;
	SingleInputAction menuAction;
};

#endif