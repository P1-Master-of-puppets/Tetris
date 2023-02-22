#include "game.h"

int Game::countLineScore(const int& nbLine)
{
	return 0;
}

Game::Game()
{
	srand(time(0));
	//_board = ColorArray2D(10, 20);
	_board.fill(Color::Transparent);
	//Fill the queue with random pieces
	// this might be changed for a less rng aproach
	for (int i = 0; i < 8; i++)
	{
		_queue.push(getRandomPiece());
	}
	_state = GameState::Initiated;
}

Game::~Game()
{
}

const ColorArray2D& Game::getBoard()
{
	return _board;
}

const Piece* Game::getPiece()
{
	return _currentPiece;
}

bool Game::rotatePieceLeft()
{
	_isDirty = true;
	return _currentPiece->rotateRight(_board);
}

bool Game::rotatePieceRight()
{
	_isDirty = true;
	return _currentPiece->rotateRight(_board);
}

bool Game::translatePieceLeft()
{
	_isDirty = true;
	return _currentPiece->translateLeft(_board);
}

bool Game::translatePieceRight()
{
	_isDirty = true;
	return _currentPiece->translateRight(_board);
}

GameState Game::getState()
{
	return _state;
}

void Game::start()
{
	_state = GameState::OnGoing;
	_currentPiece = _queue.front();
	_queue.pop();
}

bool Game::translatePieceDown()
{
	_isDirty = true;

	if (_currentPiece->translateDown(_board))
	{

	}

	return true;
}

void Game::refreshUI()
{
	if (_isDirty)
	{
		_isDirty = false;
		_display.displayBoardWithPiece(_board, _currentPiece);
	}
}

Piece* Game::getRandomPiece() {
	switch (rand() % 7)
	{
	case 0:
		return new LeftL();
		break;
	case 1:
		return new LeftS();
		break;
	case 2:
		return new LongBar();
		break;
	case 3:
		return new RightL();
		break;
	case 4:
		return new RightS();
		break;
	case 5:
		return new Square();
		break;
	case 6:
		return new Thomas();
		break;
	}
}