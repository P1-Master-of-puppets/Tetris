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
    /// Translate piece to the right
    /// </summary>
    /// <param name="board"></param>
    /// <returns></returns>
    bool translateRight(const ColorArray2D& board);
    /// <summary>
    /// Translate piece to the left
    /// </summary>
    /// <param name="board"></param>
    /// <returns></returns>
    bool translateLeft(const ColorArray2D& board);
    /// <summary>
    /// Rotates piece to the right
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if rotation failed, true if rotation suceeded</returns>
    virtual bool rotateRight(const ColorArray2D& board);
    /// <summary>
    /// Rotates piece to the left
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if rotation failed, true if rotation suceeded</returns>
    virtual bool rotateLeft(const ColorArray2D& board);
    /// <summary>
    /// Verify if pieces has a colision and needs to be placeds
    /// </summary>
    /// <param name="board">Game board</param>
    /// <returns>False if piece can still go down, true if piece touches bottom</returns>
    bool isColliding(const ColorArray2D& board);
    /// <summary>
    /// Coordinate
    /// </summary>
    /// <returns></returns>
    const Coordinate& getCoordinate();
    /// <summary>
    /// Pieces Color2DArray
    /// </summary>
    /// <returns></returns>
    const ColorArray2D* getPiece();
};

#endif // PIECE_H__
