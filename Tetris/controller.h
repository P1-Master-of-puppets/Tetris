#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include <atomic>
#include <thread>
#include "controllerInputOutput.h"
#include "SerialPort.hpp"
class Controller {
private:
	int _comport;
	int _baudRate;
	std::thread communicationThread;
	SerialPort* _arduino;
	void readThread();


	std::atomic<bool> leftTrigger;
	std::atomic<bool> rightTrigger;
	std::atomic<bool> joyStickUp;
	std::atomic<bool> joyStickDown;
	std::atomic<bool> joystickLeft;
	std::atomic<bool> joyStickRight;
	std::atomic<bool> joyStickButton;
	std::atomic<bool> aButton;
	std::atomic<bool> bButton;
	std::atomic<bool> menuButton;


public:
	Controller(int cumport, int baudRate);
	/// <summary>
	/// Connects and starts reading from arduino
	/// </summary>
	/// <returns> return false if the Arduino could not connect</returns>
	bool init();
	bool getLeftTrigger();
	bool getRightTrigger();
	bool getJoyStickUp();
	bool getJoyStickDown();
	bool getJoystickLeft();
	bool getJoyStickRight();
	bool getJoyStickButton();
	bool getAButton();
	bool getBButton();
	bool getMenuButton();

	void vibrate(int milliseconds);
	void updateSevenSegment(int twoDigitNumber);
	
	/// <summary>
	/// This is a blocking action, it will return the last value pressed on the controller
	/// </summary>
	/// <returns></returns>
	ControllerInputOutput getLastButtonPressed();

};
#endif // CONTROLLER_H__