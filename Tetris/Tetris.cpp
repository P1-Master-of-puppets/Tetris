#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"
#include "inputDevice.h"

#include <chrono>
using namespace std::chrono;

int main()
{
	std::cout << "Select starting level from 0 to 9 : ";
	int startingLevel;
	std::cin >> startingLevel;

	Game game = Game(startingLevel);

	game.start();
	game.refreshUI();
	InputDevice input;
	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

	while (game.getState() == GameState::OnGoing)
	{
		game.refreshUI();

		if (input.translateLeft())
			game.translatePieceLeft();
		else if (input.translateRight())
			game.translatePieceRight();

		if (input.rotateRight())
			game.rotatePieceRight();
		else if (input.rotateLeft())
			game.rotatePieceLeft();

		if (input.dropOnce() || duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
			lastAutomaticDrop = high_resolution_clock::now();
			game.translatePieceDown();
		}

	}
	return 0;
}