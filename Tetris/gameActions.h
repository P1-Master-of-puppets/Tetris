#pragma once
#ifndef GAME_ACTIONS_H__
#define GAME_ACTIONS_H__

#include <chrono>
#include "keyboardInput.h"
#include "action.h"
#include "holdAction.h"
#include "singleInputAction.h"
#include "translateAction.h"
#include "inputSetting.h"

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
	bool holdPiece();
	void loadSettings(InputSetting newSettings);
private:
	TranslateAction translateLeftAction;
	TranslateAction translateRightAction;
	SingleInputAction rotateRightAction;
	SingleInputAction rotateLeftAction;
	HoldAction dropFasterAction;
	SingleInputAction dropInstantAction;
	SingleInputAction menuAction;
	SingleInputAction holdPieceAction;
};

#endif