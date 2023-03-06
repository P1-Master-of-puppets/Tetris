#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"
#include "gameActions.h"

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
<<<<<<< HEAD
	GameActions actions;
	int pieceSpeed = 500;
=======
	InputDevice input;
>>>>>>> 2fd9403857110a54df33ce913e8ef4ab183533cb
	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

	while (game.getState() == GameState::OnGoing)
	{
<<<<<<< HEAD
		if (actions.translateLeft())
=======
		game.refreshUI();

		if (input.translateLeft())
>>>>>>> 2fd9403857110a54df33ce913e8ef4ab183533cb
			game.translatePieceLeft();
		else if (actions.translateRight())
			game.translatePieceRight();

		if (actions.rotateRight())
			game.rotatePieceRight();
		else if (actions.rotateLeft())
			game.rotatePieceLeft();

<<<<<<< HEAD
		if (actions.dropOnce() || duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > pieceSpeed) {
=======
		if (input.dropOnce() || duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
>>>>>>> 2fd9403857110a54df33ce913e8ef4ab183533cb
			lastAutomaticDrop = high_resolution_clock::now();
			game.translatePieceDown();
		}

	}
	return 0;
}