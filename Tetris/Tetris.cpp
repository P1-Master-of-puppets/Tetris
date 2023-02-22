// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"
#include <ctime>

int main()
{
	Game game;
	game.start();
	game.refreshUI();
	
	int pieceSpeed = 500;

	time_t ttime = time(0);

	while (game.getState() == GameState::OnGoing)
	{
		if (ttime > ttime)
		{

		}
	}
	return 0;
}