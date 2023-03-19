#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"
#include "testActions.h"
#include "gameActions.h"
#include "nlohmann/json.hpp"
#include <chrono>
#include "inputDevice.h"
#include "settingDataAccess.h"
#include "controller.h"
#include "SerialPort.hpp"

using namespace std::chrono;

int main()
{
	Controller controller(7, 115200);

	controller.updateThreatIndicator(2);
	controller.updateSevenSegment(3);
	
	while (true) {

	}

	/*std::cout << "Select starting level from 0 to 9 : ";
	int startingLevel;
	std::cin >> startingLevel;

	Game game = Game(startingLevel);

	game.start();
	game.refreshUI();
	GameActions actions;
	int pieceSpeed = 500;
	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

	while (game.getState() == GameState::OnGoing)
	{
		game.refreshUI();

		if (actions.translateLeft())
			game.translatePieceLeft();
		else if (actions.translateRight())
			game.translatePieceRight();

		if (actions.rotateRight())
			game.rotatePieceRight();
		else if (actions.rotateLeft())
			game.rotatePieceLeft();

		if (actions.dropFaster()) {
			game.translatePieceDown();
		}

		if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > pieceSpeed) {
			if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
				lastAutomaticDrop = high_resolution_clock::now();
				game.translatePieceDown();
			}

		}
	}*/
	return 0;
}