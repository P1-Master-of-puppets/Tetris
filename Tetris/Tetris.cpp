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
	Game game;
	game.start();
	game.refreshUI();
	GameActions actions;
	int pieceSpeed = 500;
	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

	while (game.getState() == GameState::OnGoing)
	{
		if (actions.translateLeft())
			game.translatePieceLeft();
		else if (actions.translateRight())
			game.translatePieceRight();

		if (actions.rotateRight())
			game.rotatePieceRight();
		else if (actions.rotateLeft())
			game.rotatePieceLeft();

		if (actions.dropOnce() || duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > pieceSpeed) {
			lastAutomaticDrop = high_resolution_clock::now();
			game.translatePieceDown();
		}

		game.refreshUI();
	}
	return 0;
}