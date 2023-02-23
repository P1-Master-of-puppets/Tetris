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
	Game game = Game(0);
	game.start();
	game.refreshUI();
	InputDevice input;
	int pieceSpeed = 500;
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

		if (input.dropOnce() || duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > pieceSpeed) {
			lastAutomaticDrop = high_resolution_clock::now();
			game.translatePieceDown();
		}

	}
	return 0;
}