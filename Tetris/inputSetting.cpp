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

	for (int i = 0; i < myJson["translateLeft"].get<std::vector<ControllerInput>>().size(); i++) {
		translateLeft.push_back(myJson["translateLeft"][i]);
	}

	for (int i = 0; i < myJson["translateRight"].get<std::vector<ControllerInput>>().size(); i++) {
		translateRight.push_back(myJson["translateRight"][i]);
	}

	for (int i = 0; i < myJson["rotateLeft"].get<std::vector<ControllerInput>>().size(); i++) {
		rotateLeft.push_back(myJson["rotateLeft"][i]);
	}

	for (int i = 0; i < myJson["rotateRight"].get<std::vector<ControllerInput>>().size(); i++) {
		rotateRight.push_back(myJson["rotateRight"][i]);
	}

	for (int i = 0; i < myJson["dropInstant"].get<std::vector<ControllerInput>>().size(); i++) {
		dropInstant.push_back(myJson["dropInstant"][i]);
	}

	for (int i = 0; i < myJson["dropFaster"].get<std::vector<ControllerInput>>().size(); i++) {
		dropFaster.push_back(myJson["dropFaster"][i]);
	}

	for (int i = 0; i < myJson["holdPiece"].get<std::vector<ControllerInput>>().size(); i++) {
		holdPiece.push_back(myJson["holdPiece"][i]);
	}

	accelerometer = myJson["accelerometer"];
	vibration = myJson["vibration"];

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

	fichier << myJson.dump(4);
	fichier.close();

	return true;
}