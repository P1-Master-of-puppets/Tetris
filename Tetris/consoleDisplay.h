#ifndef CONSOLEDISPLAY_H__
#define CONSOLEDISPLAY_H__

#include "colorArray2D.h"
#include "piece.h"
#include <iostream>

class ConsoleDisplay
{
public:
	ConsoleDisplay();
	~ConsoleDisplay();
	void display2DArray(ColorArray2D& array);
	void display2DArray(ColorArray2D& colorArray, int startLine);
	void displayBoardWithPiece(ColorArray2D& board, Piece* somePiece);
	void displayBoardWithPiece(ColorArray2D& board, Piece* somePiece, int startLine);

private:

};
#endif //CONSOLEDISPLAY_H__

