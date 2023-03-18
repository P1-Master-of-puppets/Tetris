#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include <atomic>
#include <thread>
#include "SerialPort.hpp"
#include <exception>
#include <string>
#include "controllerInputOutput.h"

class Controller {
private:
	int _comport;
	int _baudRate;
	std::thread _communicationThread;
	SerialPort* _arduino;
	std::atomic<bool> _isRunning;
	void readThread();


	std::atomic<ControllerInputOutput> _lastInput{ ControllerInputOutput::None };

	std::atomic<bool> _leftTrigger;
	std::atomic<bool> _rightTrigger;
	std::atomic<bool> _joyStickUp;
	std::atomic<bool> _joyStickDown;
	std::atomic<bool> _joystickLeft;
	std::atomic<bool> _joyStickRight;
	std::atomic<bool> _joyStickButton;
	std::atomic<bool> _aButton;
	std::atomic<bool> _bButton;
	std::atomic<bool> _menuButton;
	std::atomic<bool> _fastDrop;

	void updateControllerValues(char* buffer);
	void updateJoystickValues(char value);
public:
	Controller(int cumport, int baudRate);
	~Controller();
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
	bool getFastDrop();

	void vibrate(int milliseconds);
	void updateSevenSegment(int twoDigitNumber);
	void updateThreatIndicator(int threatLevel);

	/// <summary>
	/// This is a blocking action, it will return the last value pressed on the controller
	/// </summary>
	/// <returns></returns>
	ControllerInputOutput getLastButtonPressed();

};
#endif // CONTROLLER_H__