#include <iostream>
#include <chrono>

#include "game.h"
#include "colorArray2D.h"
#include "gameActions.h"
#include "inputDevice.h"


using namespace std::chrono;

int main()
{
	std::cout << "Select starting level from 0 to 9 : ";
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
	}


	return 0;
}