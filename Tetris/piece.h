#ifndef PIECE_H__
#define PIECE_H__

#include "colors.h"

class Piece
{
private:
    /* data */
protected:
    Color *_piece;

public:
    Piece(int height, int width);
    ~Piece();

    virtual bool rotateRight(Color *board);
    virtual bool rotateLeft(Color *board);
    bool isColliding(Color *board);
    Color *getPiece();
};

#endif // PIECE_H__
