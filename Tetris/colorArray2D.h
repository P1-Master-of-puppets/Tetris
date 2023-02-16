#ifndef COLORARRAY2D_H__
#define COLORARRAY2D_H__

#include"colors.h"
//https://www.geeksforgeeks.org/cpp-return-2d-array-from-function/
class ColorArray2D {
private:
	int _width;
	int _height;
	Color** _grid;
public:
	ColorArray2D(const ColorArray2D& colorArray2D);
	ColorArray2D(int width, int height);
	~ColorArray2D();
	void fill(Color color);
	int getHeight();
	int getWidth();
	Color** getGrid() const;
};
#endif //COLORARRAY2D_H__