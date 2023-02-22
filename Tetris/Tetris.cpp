#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"
#include "inputDevice.h"
#include <ctime>

int main()
{
	Game game;
	game.start();
	game.refreshUI();
	InputDevice input;
	int pieceSpeed = 500;

	time_t ttime = time(0);

	while (game.getState() == GameState::OnGoing)
	{
		if (input.translateLeft())
			game.translatePieceLeft();
		
	}
	return 0;
}