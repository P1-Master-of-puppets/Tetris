#ifndef TESTPIECE_H__
#define TESTPIECE_H__

#include <iostream>
#include "piece.h"
#include "consoleDisplay.h"
#include "colorArray2D.h"
#include "thomas.h"

class TestPiece
{
public:
	static void testTranslateRight();
	static void testTranslateLeft();
	static void testRotateRight();
	static void testRotateLeft();
	static void testIsColliding();
};

#endif // TESTPIECE_H__