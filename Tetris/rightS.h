#ifndef RightS_H__
#define RightS_H__

#include "piece.h"
#include "type.h"


class RightS : public Piece
{
public:
    RightS();
    ~RightS();
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);
    virtual bool resetPieceTodefault();
private:
    bool rotateS(const ColorArray2D& board);
    bool isVertical;
};

#endif // RightS_H__