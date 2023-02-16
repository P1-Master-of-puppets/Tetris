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

ColorArray2D::ColorArray2D(const ColorArray2D& colorArray2D) : ColorArray2D(_height, _width)
{
	_height = colorArray2D._height;
	_width = colorArray2D._width;

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			_grid[i][j] = colorArray2D._grid[i][j];
		}
	}
}

ColorArray2D::ColorArray2D(int width, int height)
{
	_height = height;
	_width = width;
	_grid = new Color * [height];
	for (int i = 0; i < height; i++)
	{
		_grid[i] = new Color[width];
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

void ColorArray2D::fill(Color color)
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			_grid[i][j] = color;
		}
	}
}
