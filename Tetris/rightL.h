#ifndef RightL_H__
#define RightL_H__

#include "piece.h"
#include "type.h"

class RightL : public Piece
{
public:
    RightL();
    ~RightL();
    virtual bool resetPieceTodefault();
};

#endif // RightL_H__