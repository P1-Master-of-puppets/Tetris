#include "game.h"

int Game::countLineScore(const int& nbLine)
{
	return 0;
}

Game::Game()
{
	_board = ColorArray2D(10, 20);
}

Game::~Game()
{
}

const ColorArray2D& Game::getBoard()
{
	return _board;
	// TODO: insert return statement here
}

const Piece* Game::getPiece()
{
	return _currentPiece;
	// TODO: insert return statement here
}

const ColorArray2D& Game::getBoardWithPiece()
{
	return ColorArray2D(1,1);
}

bool Game::rotatePieceLeft()
{
	return false;
}

bool Game::rotatePieceRight()
{
	return false;
}

bool Game::translatePieceLeft()
{
	return false;
}

bool Game::translatePieceRight()
{
	return false;
}
