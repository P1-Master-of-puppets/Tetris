#include "consoleDisplay.h"

void displayWithColor(Color color) {
	switch (color)
	{
	case Color::Transparent:
		std::cout << ". ";
		break;
	case Color::Cyan:
		std::cout << "\x1B[36m# \033[0m";
		break;
	case Color::Yellow:
		std::cout << "\x1B[33m# \033[0m";
		break;
	case Color::Purple:
		std::cout << "\x1B[35m# \033[0m";
		break;
	case Color::Green:
		std::cout << "\x1B[32m# \033[0m";
		break;
	case Color::Blue:
		std::cout << "\x1B[34m# \033[0m";
		break;
	case Color::Red:
		std::cout << "\x1B[31m# \033[0m";
		break;
	case Color::Orange:
		std::cout << "\x1B[37m# \033[0m";
		break;
	default:
		break;
	}
}

void displayWithoutColor(Color color) {
	switch (color)
	{
	case Color::Transparent:
		std::cout << ". ";
		break;
	case Color::Cyan:	std::cout << "C "; break;
	case Color::Yellow: std::cout << "Y "; break;
	case Color::Purple: std::cout << "P "; break;
	case Color::Green:	std::cout << "G "; break;
	case Color::Blue:	std::cout << "B "; break;
	case Color::Red:	std::cout << "R "; break;
	case Color::Orange: std::cout << "O "; break;
	default:
		std::cout << "# ";
		break;
	}
}


ConsoleDisplay::ConsoleDisplay()
{
}

ConsoleDisplay::~ConsoleDisplay()
{
}

void ConsoleDisplay::displayBoardWithPiece(ColorArray2D& board, Piece* somePiece){

	ColorArray2D combinedBoard = ColorArray2D(board);

	for(int i = 0; i < somePiece->getPiece()->getHeight(); i++){
		for(int j = 0; j < somePiece->getPiece()->getWidth(); j++){
			if(somePiece->getCoordinate().y + i < board.getHeight() && 
			   somePiece->getCoordinate().y + i >= 0 &&
			   somePiece->getCoordinate().x + j < board.getWidth() &&
			   somePiece->getCoordinate().x + j >= 0){
				if ((*somePiece->getPiece())[i][j] != Color::Transparent)
				{
					combinedBoard[somePiece->getCoordinate().y + i][somePiece->getCoordinate().x + j] = (*somePiece->getPiece())[i][j];
				}
			}
		}
	}

	display2DArray(combinedBoard);

}

void ConsoleDisplay::display2DArray(ColorArray2D& colorArray)
{
	for(int i = 0; i < colorArray.getWidth()*2 + 3; i++){
		std::cout << "#";
	}

	std::cout << "\n" << "#";

	//Change console color only if in windows.
	//Linux might be using a different lib.
	Color currentColor;
	for (int i = 0; i < colorArray.getHeight(); i++)
	{
		std::cout << " ";
		for (int j = 0; j < colorArray.getWidth(); j++)
		{
			displayWithColor(colorArray.getGrid()[i][j]);
			//displayWithoutColor(colorArray.getGrid()[i][j]);
		}
		std::cout << "#" << "\n" << "#";
	}

	for(int i = 0; i < colorArray.getWidth()*2 + 2; i++){
		std::cout << "#";
	}

	std::cout << "\n";

}

