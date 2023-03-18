#include "inputSetting.h"

bool InputSetting::readSettings(std::string fileName)
{
	std::ifstream fichier(fileName);
	nlohmann::json myJson;

	if (!fichier.is_open()) {
		std::cout << "Can't open file " << fileName << " for read" << std::endl;
		return false;
	}

	myJson = nlohmann::json::parse(fichier);
	std::cout << myJson.dump() << std::endl;

	return true;
}

bool InputSetting::writeSettings(std::string fileName)
{
	std::ofstream fichier(fileName);
	nlohmann::json myJson;
	
	if (!fichier.is_open()) {
		std::cout << "Can't open file " << fileName << " for write" << std::endl;
		return false;
	}

	myJson["translateLeft"] = translateLeft;
	myJson["translateRight"] = translateRight;
	myJson["rotateRight"] = rotateRight;
	myJson["rotateLeft"] = rotateLeft;
	myJson["dropInstant"] = dropInstant;
	myJson["dropFaster"] = dropFaster;
	myJson["holdPiece"] = holdPiece;
	myJson["accelerometer"] = accelerometer;
	myJson["vibration"] = vibration;

	fichier << myJson.dump();
	fichier.close();

	return true;
}