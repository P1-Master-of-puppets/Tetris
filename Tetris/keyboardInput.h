#ifndef KEYBOARD_INPUT
#define KEYBOARD_INPUT

#include <Windows.h>

class KeyboardInput
{
public:
	bool translateLeft();
	bool translateRight();
	bool rotateRight();
	bool rotateLeft();
	bool dropInstant();
	bool dropFaster();
	bool holdPiece();
	bool menu();
};

#endif