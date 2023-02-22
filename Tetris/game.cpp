#include "game.h"


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
	if (_currentPiece->rotateRight(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::rotatePieceRight()
{

	if (_currentPiece->rotateRight(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceLeft()
{
	if (_currentPiece->translateLeft(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceRight()
{
	if (_currentPiece->translateRight(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceDown()
{
	_isDirty = true;

	if (!_currentPiece->translateDown(_board))
	{
		putPieceInBoard();
		delete _currentPiece;
		_currentPiece = _queue.front();
		_queue.pop();
		_queue.push(getRandomPiece());

		int rowAmount = 0;
		int* rows = getFullRows(rowAmount);
		removeRows(rows, rowAmount);
		delete rows;
	}

	return true;
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

void Game::refreshUI()
{
	if (_isDirty)
	{
		_isDirty = false;
		_display.displayBoardWithPiece(_board, _currentPiece);
		std::cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
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

int* Game::getFullRows(int& size)
{
	int* values = new int[4];

	int rowAmount = 0;

	for (int i = 0; i < _board.getHeight(); i++)
	{
		for (int j = 0; j < _board.getWidth(); j++)
		{
			if (_board.getGrid()[i][j] == Color::Transparent)
				break;

			if (j == _board.getWidth() - 1)
			{
				values[rowAmount] = i;
				rowAmount++;
			}
		}
	}
	size = rowAmount;
	return values;
}

void Game::removeRows(int* rows, int& size) {


	//remove all rows
	for (int i = 0; i < size; i++)
	{
		delete[] _board.getGrid()[rows[i]];


		for (int j = rows[i] - 1; j >= 0; j--)
		{
			_board.getGrid()[j + 1] = _board.getGrid()[j];
		}
		_board.getGrid()[0] = new Color[_board.getWidth()];

		for (int i = 0; i < _board.getWidth(); i++)
		{
			_board.getGrid()[0][i] = Color::Transparent;
		}
	}
}

void Game::putPieceInBoard()
{
	for (int i = 0; i < _currentPiece->getPiece()->getHeight(); i++) {
		for (int j = 0; j < _currentPiece->getPiece()->getWidth(); j++) {
			if (_currentPiece->getCoordinate().y + i < _board.getHeight() &&
				_currentPiece->getCoordinate().y + i >= 0 &&
				_currentPiece->getCoordinate().x + j < _board.getWidth() &&
				_currentPiece->getCoordinate().x + j >= 0) {

				if ((*_currentPiece->getPiece())[i][j] != Color::Transparent)
				{
					_board[_currentPiece->getCoordinate().y + i][_currentPiece->getCoordinate().x + j] = (*_currentPiece->getPiece())[i][j];
				}
			}
		}
	}
}

int Game::countLineScore(const int& nbLine)
{
	return 0;
}