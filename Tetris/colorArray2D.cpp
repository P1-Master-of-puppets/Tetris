#include "colorArray2D.h"

int ColorArray2D::getHeight()
{
	return _height;
}
int ColorArray2D::getWidth()
{
	return _width;
}

Color** ColorArray2D::getGrid()
{
	return _grid;
}

ColorArray2D::ColorArray2D(int width, int height)
{
	_height = height;
	_width = width;
	_grid = new Color*[width];
	for (int i = 0; i < width; i++)
	{
		_grid[i] = new Color[height];
	}
}

ColorArray2D::~ColorArray2D()
{
	for (int i = 0; i < _width; i++)
	{
		delete[] _grid[i];
	}
	delete[] _grid;
}
