#ifndef KEYBOARD_INPUT
#define KEYBOARD_INPUT

#include <Windows.h>

class KeyboardInput {

public:
	static bool translateLeft();
	static bool translateRight();
	static bool rotateRight();
	static bool rotateLeft();
	static bool dropFaster();
	static bool dropOnce();
};

#endif