#pragma once
#ifndef SETTING_H__
#define SETTING_H__

#include <vector>
#include <string>

#include "controllerInput.h"

class Setting {
public:
	bool readSettings(std::string fileName);
	bool writeSettings(std::string fileName);
	std::vector<ControllerInput> translateLeft;
	std::vector<ControllerInput> translateRight;
	std::vector<ControllerInput> rotateRight;
	std::vector<ControllerInput> rotateLeft;
	std::vector<ControllerInput> dropInstant;
	std::vector<ControllerInput> dropFaster;
	std::vector<ControllerInput> holdPiece;
	bool accelerometer;
	bool vibration;
};

#endif // !SETTING_H__

