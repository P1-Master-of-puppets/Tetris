#ifndef GAME_H__
#define GAME_H__

#include "piece.h"
#include <iostream>
#include <queue>

class Game
{
private:
    Piece* _currentPiece = nullptr;
    ColorArray2D _board = ColorArray2D(10,20);
    unsigned int _score = 0;
    std::queue<Piece> _queue;

    int countLineScore(const int& nbLine);
public:
    Game();
    ~Game();

    const ColorArray2D& getBoard();
    const Piece* getPiece();
    const ColorArray2D getBoardWithPiece();
    bool rotatePieceLeft();
    bool rotatePieceRight();
    bool translatePieceLeft();
    bool translatePieceRight();
};

#endif // GAME_H__
