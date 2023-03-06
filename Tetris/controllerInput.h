#ifndef CONTROLLER_INPUT_H__
#define CONTROLLER_INPUT_H__

#include <Windows.h>
#include "controlInterface.h"

class ControllerInput : public ControlInterface
{
public:
	static bool translateLeft();
	static bool translateRight();
	static bool rotateRight();
	static bool rotateLeft();
	static bool dropInstant();
	static bool dropFaster();
	static bool holdPiece();
	static bool menu();
};

#endif#pragma once
