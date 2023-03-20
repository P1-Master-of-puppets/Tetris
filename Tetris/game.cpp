#include "game.h"


Game::Game(int level)
{
	_level = level;
	srand(time(0));
	_board.fill(Color::Transparent);
	updateLvlAndGravity();
	setGravity();
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

Piece* Game::getPiece()
{
	return _currentPiece;
}

int Game::getLevel()
{
	return _level;
}

int Game::getGravitySpeed()
{
	return _gravityspeed_milliseconds;
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
		_score += countLineScore(rowAmount);
		_totalLines += rowAmount;
		updateLvlAndGravity();
		//Verify if the game is lost
		return !gameLost();
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
		system("CLS");
		std::cout << "\nScore: " << _score << "\n" << "Level: " << _level << "\n" << "Nb of lines: " << _totalLines << "\n";

		_display.displayBoardWithPiece(_board, _currentPiece, extraRow);

	}
}

Piece* Game::getRandomPiece() {
	switch (rand() % 7)
	{
	case 0:
		return new LeftL();
	case 1:
		return new LeftS();
	case 2:
		return new LongBar();
	case 3:
		return new RightL();
	case 4:
		return new RightS();
	case 5:
		return new Square();
	case 6:
		return new Thomas();
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
	_currentPiece->addToColorArray2D(_board);
}

bool Game::gameLost()
{
	//Verify if new piece is over a current piece
	if (_currentPiece->isColliding(_currentPiece->getPiece(), _currentPiece->getCoordinate(), _board))
	{
		_state = GameState::Finished;
		return true;
	}

	//Verify if pices are higher than the displayed one
	for (int i = 0; i < _board.getWidth(); i++)
	{
		if (_board.getGrid()[extraRow - 1][i] != Color::Transparent)
		{
			GameState::Finished;
			return true;
		}
	}
	return false;
}

void Game::updateLvlAndGravity()
{
	if ((_level + 1) * 10 <= _totalLines)
	{
		_level++;
		setGravity();
	}
}

void Game::setGravity()
{
	if (_level < 9)
	{
		_gravityspeed_milliseconds = 1000* (((double)48 - ((double)_level * (double)5)) / (double)60);
	}
	else if (_level == 9)
	{
		_gravityspeed_milliseconds = ((double)6 / (double)60) * 1000;
	}
	else if (_level >= 10 && _level <= 12)
	{
		_gravityspeed_milliseconds = ((double)5 / (double)60)* 1000;
	}
	else if(_level >= 13 && _level <= 15)
	{
		_gravityspeed_milliseconds = ((double)4 / (double)60) * 1000;
	}
	else if (_level >= 16 && _level <= 18)
	{
		_gravityspeed_milliseconds = ((double)3 / (double)60) * 1000;
	}
	else if (_level >= 19 && _level <= 28)
	{
		_gravityspeed_milliseconds = ((double)2 / (double)60) * 1000;
	}
	else 
	{
		_gravityspeed_milliseconds = ((double)1 / (double)60) * 1000;
	}
}

int Game::countLineScore(const int& nbLine)
{
	switch (nbLine)
	{
	case 1:
		return 40 * (_level + 1);
	case 2:
		return 100 * (_level + 1);
	case 3:
		return 300 * (_level + 1);
	case 4:
		return 1200 * (_level + 1);
	default:
		return 0;
	}
}

// FONCTION HOLD (ajout� par Daniel)

// �change la pi�ce en courante avec la pi�ce de r�serve
void Game::swapPiece() 
{
	//_currentPiece->printInfoPiece();
	

	//std::cout << "\n La pi�ce courante est : " << std::endl;


	Coordinate newCoord;
	newCoord.x = _currentPiece->getX();
	newCoord.y = _currentPiece->getY();
	if (getHoldPiece()->isColliding(getHoldPiece()->getPiece(), newCoord, _board)) {
		return;
	}

	_isDirty = true;
	// Mettre la pi�ce courante dans une variable temporaire 
	Piece* tmpPiece = _currentPiece;

	// Red�fini la pi�ce courante avec la pi�ce en r�serve
	_currentPiece = getHoldPiece();

	// D�fini la pi�ce de r�serve avec la pi�ce temporaire
	_holdPiece = tmpPiece;
	_currentPiece->setToCurrentPosition(tmpPiece->getX(), tmpPiece->getY());
	//_currentPiece->resetCoordinate();

	//std::cout << "swapPiece() A ETE APPELLE.\n" << std::endl;

	//_currentPiece->printInfoPiece();

	return;
}

// R�cup�re la pi�ce en r�serve
Piece* Game::getHoldPiece()
{
	if (_holdPiece == nullptr)
	{
		_holdPiece = _queue.front();
		_queue.pop();
		_queue.push(getRandomPiece());

	}

	return _holdPiece;
}
