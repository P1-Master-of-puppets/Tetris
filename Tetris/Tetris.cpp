// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"
#include "colorArray2D.h"
#include "testDisplay.h"
#include "testPiece.h"

int main()
{
    Game game;

	game.start();

	while (game.getState() == GameState::OnGoing)
	{
		
	}
    return 0;
}