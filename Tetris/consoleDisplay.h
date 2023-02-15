#ifndef CONSOLEDISPLAY_H__
#define CONSOLEDISPLAY_H__

#include "colorArray2D.h"
#include <iostream>

//#include "colorDisplay.hpp"



class ConsoleDisplay
{
public:
	ConsoleDisplay();
	~ConsoleDisplay();
	void display2DArray(ColorArray2D& array);
private:

};
#endif //CONSOLEDISPLAY_H__

