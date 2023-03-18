#include "settingDataAccess.h"

const std::string SettingDataAccess::FILE_NAME = "settings.txt";

Setting SettingDataAccess::readSetting()
{
	Setting newSetting;
	ifstream file(FILE_NAME);

	if (json settingFile = json::parse(file))
	{
		newSetting.translateLeft.clear();
		newSetting.translateLeft.push_back(settingFile["translateLeft"]);
		newSetting.translateRight.clear();
		newSetting.translateRight.push_back(settingFile["translateRight"]);
		newSetting.rotateLeft.clear();
		newSetting.rotateLeft.push_back(settingFile["rotateLeft"]);
		newSetting.rotateRight.clear();
		newSetting.rotateRight.push_back(settingFile["rotateRight"]);
		newSetting.dropFaster.clear();
		newSetting.dropFaster.push_back(settingFile["dropFaster"]);
		newSetting.dropInstant.clear();
		newSetting.dropInstant.push_back(settingFile["dropInstant"]);
		newSetting.holdPiece.clear();
		newSetting.holdPiece.push_back(settingFile["holdPiece"]);
		newSetting.accelerometer = settingFile["accelerometer"];
		newSetting.vibration = settingFile["vibration"];
	}

	return newSetting;
}

void SettingDataAccess::writeSetting(Setting setting)
{
	json settingFile;
	settingFile["translateLeft"] = setting.translateLeft;
	settingFile["translateRight"] = setting.translateRight;
	settingFile["rotateLeft"] = setting.rotateLeft;
	settingFile["rotateRight"] = setting.rotateRight;
	settingFile["dropFaster"] = setting.dropFaster;
	settingFile["dropInstant"] = setting.dropInstant;
	settingFile["holdPiece"] = setting.holdPiece;
	settingFile["accelerometer"] = setting.accelerometer;
	settingFile["vibration"] = setting.vibration;

	ofstream wright;
	wright.open(FILE_NAME);
	wright << settingFile.dump();
	wright.close();

}
