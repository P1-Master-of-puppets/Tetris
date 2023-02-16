#include "colorArray2D.h"

int ColorArray2D::getHeight() const
{
	return _height;
}
int ColorArray2D::getWidth() const
{
	return _width;
}

Color** ColorArray2D::getGrid() const
{
	return _grid;
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

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			_grid[i][j] = Color::Transparent;
		}
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

const Color* ColorArray2D::operator[](int i) const{
	return _grid[i];
}

Color* ColorArray2D::operator[](int i){
	return _grid[i];
}
