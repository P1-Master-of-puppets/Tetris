#include "controller.h"

void Controller::readThread()
{
	std::string input;
	while (_isRunning)
	{
		char char_buffer[2];
		int buffer_size;
		std::string str_buffer;

		// This will read 
		buffer_size = _arduino->readSerialPort(char_buffer, 2);
		
		str_buffer.assign(char_buffer, buffer_size);
		input.append(str_buffer);
		//Make sure we only send 2 char at a time. Otherwise we might skip data and it will become extra weird
		updateControllerValues(char_buffer);
	}
}

void Controller::updateControllerValues(char* buffer) {
#ifndef ControllerDebug
	std::cout << '\n' << buffer[0] << " " << buffer[1] << '\n';
#endif // !ControllerDebug

	switch (buffer[0])
	{
	case 'L':
		_leftTrigger = buffer[1] == '1';
		_lastInput = ControllerInputOutput::LeftTrigger;
		return;
	case 'R':
		_rightTrigger = buffer[1] == '1';
		_lastInput = ControllerInputOutput::RightTrigger;
		return;
	case 'J':
		updateJoystickValues(buffer[1]);
		return;
	case 'A':
		_aButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::AButton;
		return;
	case 'B':
		_bButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::BButton;
		return;
	case 'M':
		_menuButton = buffer[1] == '1';
		return;
	case 'G':
		_joyStickButton = buffer[1] == '1';
		_lastInput = ControllerInputOutput::JoyStickButton;
	case 'Y':
		_fastDrop = true;
	default:
		break;
	}
}

void Controller::updateJoystickValues(char value) {
	_joyStickUp = value == 'U';
	_joyStickDown = value == 'D';
	_joystickLeft = value == 'L';
	_joyStickRight = value == 'R';
	switch (value)
	{
	case 'U':
		_lastInput = ControllerInputOutput::JoyStickUp;
		break;
	case 'D':
		_lastInput = ControllerInputOutput::JoyStickDown;
		break;
	case 'L':
		_lastInput = ControllerInputOutput::JoyStickLeft;
		break;
	case 'R':
		_lastInput = ControllerInputOutput::JoyStickRight;
		break;
	}
}



Controller::Controller(int cumport, int baudRate)
{
	_arduino = nullptr;
	_comport = cumport;
	_baudRate = baudRate;
}

Controller::~Controller()
{
	_arduino->closeSerial();
	delete _arduino;
	_isRunning = false;
	// Wait for the thread to finish before destroying the object
	_communicationThread.join();
}

bool Controller::init()
{
	std::string port = "Com" + std::to_string(_comport);
	_arduino = new SerialPort(port.c_str(), _baudRate);
	
	if (!_arduino->isConnected())
		return false;
	
	_isRunning = true;
	_communicationThread = std::thread(&Controller::readThread, this);
	return true;
}

bool Controller::getLeftTrigger()
{
	return _leftTrigger;
}

bool Controller::getRightTrigger()
{
	return _rightTrigger;
}

bool Controller::getJoyStickUp()
{
	return _joyStickUp;
}

bool Controller::getJoyStickDown()
{
	return _joyStickDown;
}

bool Controller::getJoystickLeft()
{
	return _joystickLeft;
}

bool Controller::getJoyStickRight()
{
	return _joyStickRight;
}

bool Controller::getJoyStickButton()
{
	return _joyStickButton;
}

bool Controller::getAButton()
{
	return _aButton;
}

bool Controller::getBButton()
{
	return _bButton;
}

bool Controller::getMenuButton()
{
	return _menuButton;
}

bool Controller::getFastDrop()
{
	bool temp = _fastDrop;
	_fastDrop = false;
	return temp;
}

void Controller::vibrate(int milliseconds)
{
	char time = (char)milliseconds;
	char* data = new char[2];
	data[0] = 'V';
	data[1] = time;
	_arduino->writeSerialPort(data, 2);
	delete[] data;
}

void Controller::updateSevenSegment(int twoDigitNumber)
{
	if (twoDigitNumber >= 99 || twoDigitNumber < 0)
	{
		return;
	}
	char* data = new char[2];
	char number = (char)twoDigitNumber;
	data[0] = 'S';
	data[1] = number;
	_arduino->writeSerialPort(data, 2);
	delete[] data;
}

ControllerInputOutput Controller::getLastButtonPressed()
{
	_lastInput = ControllerInputOutput::None;
	// Wait for an other thread to change the value
	while (_lastInput == ControllerInputOutput::None)
	{
		//Put a sleep not to overload the CPU
		Sleep(5);
	}
	return _lastInput;
}
