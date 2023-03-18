#ifndef KEYBOARD_INPUT
#define KEYBOARD_INPUT

#include <Windows.h>

class KeyboardInput
{
public:
	bool keyIsPressed(int key);
	static bool translateLeft();
	static bool rotateRight();
	static bool translateRight();
	static bool rotateLeft();
	static bool dropInstant();
	static bool dropFaster();
	static bool holdPiece();
	static bool menu();
};

#endif