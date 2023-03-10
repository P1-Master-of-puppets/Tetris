#ifndef SETTINGDATAACCESS_H__
#define SETTINGDATAACCESS_H__

#include "setting.h"
#include <string>

class SettingDataAccess
{
public:
	static const std::string FILE_NAME;
	static Setting readSetting();
	static void writeSetting(Setting setting);
};

#endif
