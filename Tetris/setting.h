#ifndef SETTING_H__
#define SETTING_H__
#include <vector>
#include "constrollerInput.h"
class Setting
{
public:
	std::vector<ConstrollerInput> translateLeft;
	std::vector<ConstrollerInput> translateRight;
	std::vector<ConstrollerInput> rotateRight;
	std::vector<ConstrollerInput> rotateLeft;
	std::vector<ConstrollerInput> dropInstant;
	std::vector<ConstrollerInput> dropFaster;
	std::vector<ConstrollerInput> holdPiece;
	bool accelerometer;
	bool vibration;
	
	Setting();
	~Setting();
};

#endif