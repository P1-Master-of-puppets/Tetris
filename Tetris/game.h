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
#include <vector>

class Game
{
private:
    GameState _state;
    Piece* _currentPiece = nullptr;
    ColorArray2D _board = ColorArray2D(10,20);
    ConsoleDisplay _display;
    std::queue<Piece*> _queue;
    unsigned int _score = 0;
    bool _isDirty = true;



    int* getFullRows(int& size);
    void removeRows(int* rows, int& size);
    int countLineScore(const int& nbLine);
    Piece* getRandomPiece();
    void putPieceInBoard();
public:
    Game();
    ~Game();

    const ColorArray2D& getBoard();
    const Piece* getPiece();
    bool rotatePieceLeft();
    bool rotatePieceRight();
    bool translatePieceLeft();
    bool translatePieceRight();
    bool translatePieceDown();
    GameState getState();
    void start();
    void refreshUI();
};

#endif // GAME_H__
