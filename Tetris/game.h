#ifndef GAME_H__
#define GAME_H__

#include "piece.h"
#include "leftL.h"
#include "leftS.h"
#include "longBar.h"
#include "rightL.h"
#include "rightS.h"
#include "square.h"
#include "thomas.h"
#include "gameState.h"
#include "consoleDisplay.h"
#include <iostream>
#include <queue>

class Game
{
private:
    GameState _state;
    Piece* _currentPiece = nullptr;
    ColorArray2D _board = ColorArray2D(10,20);
    unsigned int _score = 0;
    std::queue<Piece*> _queue;
    int a = 5;
    ConsoleDisplay _display;
    int countLineScore(const int& nbLine);
    Piece* getRandomPiece();
public:
    Game();
    ~Game();

    const ColorArray2D& getBoard();
    const Piece* getPiece();
    bool rotatePieceLeft();
    bool rotatePieceRight();
    bool translatePieceLeft();
    bool translatePieceRight();
    GameState getState();
    void start();
    void refreshUI();
};

#endif // GAME_H__
