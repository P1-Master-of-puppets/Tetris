#include "consoleDisplay.h"

void displayWithColor(Color color) {
	//switch (color)
	//{
	//case Color::Transparent:
	//	std::cout << " ";
	//	break;
	//case Color::Cyan:
	//	std::cout << hue::aqua << "#" << hue::reset;
	//	break;
	//case Color::Yellow:
	//	std::cout << hue::yellow << "#" << hue::reset;
	//	break;
	//case Color::Purple:
	//	std::cout << hue::purple << "#" << hue::reset;
	//	break;
	//case Color::Green:
	//	std::cout << hue::green << "#" << hue::reset;
	//	break;
	//case Color::Blue:
	//	std::cout << hue::blue << "#" << hue::reset;
	//	break;
	//case Color::Red:
	//	std::cout << hue::red << "#" << hue::reset;
	//	break;
	//case Color::Orange:
	//	std::cout << hue::white << "#" << hue::reset;
	//	break;
	//default:
	//	break;
	//}
}

void displayWithoutColor(Color color) {
	switch (color)
	{
	case Color::Transparent:
		std::cout << " ";
		break;
	case Color::Cyan:
	case Color::Yellow:
	case Color::Purple:
	case Color::Green:
	case Color::Blue:
	case Color::Red:
	case Color::Orange:
	default:
		std::cout << "#";
		break;
	}
}


ConsoleDisplay::ConsoleDisplay()
{
}

ConsoleDisplay::~ConsoleDisplay()
{
}

void ConsoleDisplay::display2DArray(ColorArray2D& colorArray)
{
	//Change console color only if in windows.
	//Linux might be using a different lib.
	Color currentColor;
	for (int i = 0; i < colorArray.getHeight(); i++)
	{
		for (int j = 0; j < colorArray.getWidth(); j++)
		{
			displayWithoutColor(colorArray.getGrid()[i][j]);
		}
		std::cout << std::endl;
	}
}

