#include "circle.h"

void Circle::draw()
{
	drawCircle(center_x, center_y, radius, thick, q, w, e);
}

void Circle::drawCircle(int center_x, int center_y, int radius, int thick, float q, float w, float e)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((j - center_y)*(j - center_y) + (i - center_x)*(i - center_x) <= radius*radius)
			{
				drawPixel(i, j, q, w, e);
			}
			if ((j - center_y)*(j - center_y) + (i - center_x)*(i - center_x) < radius*radius - (radius*radius / thick))
			{
				drawPixel(i, j, 1.0f, 1.0f, 1.0f);
			}
		}
	}


}



// it contained for mouse effect

bool Circle::isInsideCircle(double x, double y, int a, int b,int r)
{

	const double f = (x - a)*(x - a) + (y - b)*(y - b) - r*r;

	if (f > 0.0) return false;
	else	return true;

}
