#ifndef SETTINGDATAACCESS_H__
#define SETTINGDATAACCESS_H__

#include <string>
#include <fstream>
#include <iostream>
#include "setting.h"
#include "nlohmann/json.hpp"
#include "constrollerInput.h"

using namespace std;
using json = nlohmann::json;

class SettingDataAccess
{
public:
	static const std::string FILE_NAME;
	static Setting readSetting();
	static void writeSetting(Setting setting);

private: 
	
};

#endif
