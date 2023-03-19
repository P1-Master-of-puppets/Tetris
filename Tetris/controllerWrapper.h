#ifndef CONTROLLERWRAPPER_H__
#define CONTROLLERWRAPPER_H__

#include "controller.h"

class ControllerWrapper {
private:
public:
	static const Controller controller;
	static bool getLeftTrigger();
	static bool getRightTrigger();
	static bool getJoyStickUp();
	static bool getJoyStickDown();
	static bool getJoystickLeft();
	static bool getJoyStickRight();
	static bool getJoyStickButton();
	static bool getAButton();
	static bool getBButton();
	static bool getMenuButton();
	static bool getFastDrop();
};
#endif // CONTROLLERWRAPPER_H__