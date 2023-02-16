#ifndef PIECE_H__
#define PIECE_H__

#include "colorArray2D.h"
#include "coordinate.h"

class Piece
{
protected:
    ColorArray2D*  _array;
    Coordinate _coordinate;
public:
    Piece(int width, int height);
    virtual ~Piece() = 0;

    /// <summary>
    /// Rotates piece to the right
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if rotation failed, true if rotation suceeded</returns>
    virtual bool rotateRight(const ColorArray2D& board) = 0;
    /// <summary>
    /// Rotates piece to the left
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if rotation failed, true if rotation suceeded</returns>
    virtual bool rotateLeft(const ColorArray2D& board) = 0;
    /// <summary>
    /// Verify if pieces has a colision and needs to be placeds
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if piece can still go down, true if piece touches bottom</returns>
    bool isColliding(const Piece* future, const ColorArray2D& board);
    /// <summary>
    /// Coordinate
    /// </summary>
    /// <returns></returns>
    const Coordinate& getCoordinate() const;
    /// <summary>
    /// Pieces Color2DArray
    /// </summary>
    /// <returns></returns>
    ColorArray2D* getPiece() const;
};

#endif // PIECE_H__
