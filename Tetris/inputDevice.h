#ifndef INPUT_DEVICE
#define INPUT_DEVICE

#include <chrono>
#include "keyboardInput.h"

using namespace std::chrono;

class InputDevice
{
private:
	const int inputDelay = 150;
	high_resolution_clock::time_point lastTranslateLeft;
	high_resolution_clock::time_point lastTranslateRight;
	high_resolution_clock::time_point lastRotateLeft;
	high_resolution_clock::time_point lastRotateRight;
	high_resolution_clock::time_point lastDropFaster;
	high_resolution_clock::time_point lastDropOnce;


public:
	InputDevice();
	bool translateLeft();
	bool translateRight();
	bool rotateRight();
	bool rotateLeft();
	bool dropFaster();
	bool dropOnce();
};

#endif