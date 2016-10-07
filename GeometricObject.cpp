#include "GeometricObject.h"
#include "circle.h"
#include "box.h"
#include "inicon.h"


void GeometricObject::whitebg(float* pixels, int width, int height)
{
	std::fill_n(pixels, width*height * 3, 1.0f);
}

double GeometricObject::getRandomNumber(const double min, const double max)
{
	// temp >= 0.0 && temp <= 1.0
	double temp = (double)rand() / (double)RAND_MAX;

	// temp >= min && temp <= max
	temp = min + (max - min)*temp;

	return temp;
}


void GeometricObject::drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void GeometricObject::drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void GeometricObject::drawLine2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	/*double k = getRandomNumber(0.0, 100.0);*/

	if (i0 == i1)
	{
		for (int i = j0; i <= j1; i++)
		{
			drawPixel(i0, i, red, green, blue);
		}
	}
	if (j0 == j1)
		for (int i = i0; i <= i1; i++)
		{
			drawPixel(i, j0, red, green, blue);
		}
}

void GeometricObject::drawCircle(int center_x, int center_y, int radius, int thick, float q, float w, float e)
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

bool GeometricObject::isInsideCircle(double x, double y, int a, int b,int r)
{
	const double f = (x - a)*(x - a) + (y - b)*(y - b) - r*r;

	if (f > 0.0) return false;
	else	return true;

}

void GeometricObject::drawBox(int x, int y, int r, float q, float w, float e)
{
	drawLine2(x - r, y - r, x - r, y + r, q, w, e);
	drawLine2(x - r, y + r, x + r, y + r, q, w, e);
	drawLine2(x - r, y - r, x + r, y - r, q, w, e);
	drawLine2(x + r, y - r, x + r, y + r, q, w, e);
}

bool GeometricObject::isInsideBox(double x, double y, int a, int b, int r)
{

	if ((a - r <= x) && (x <= a + r) && (b - r <= y) && (y <= b + r)) return true;
	else	return false;


}


void GeometricObject::drawMinicon(char A[20], int x, int y, int r, float q, float w, float e)
{
	if (A == "thickline")
	{
		drawLine(x - r, y - r, x + r, y + r, q, w, e);
		drawLine(x - r - 1, y - r, x + r + 1, y + r + 1, q, w, e);
		drawLine(x - r, y - r - 1, x + r + 1, y + r, q, w, e);

	}

	if (A == "X")
	{
		drawLine(x - r, y - r, x + r, y + r, q, w, e);
		drawLine(x - r, y + r, x + r, y - r, q, w, e);

	}

	if (A == "A")
	{
		drawLine(x - r, y - r, x, y + r, q, w, e);
		drawLine(x, y + r, x + r, y - r, q, w, e);
		drawLine2(x - (r / 2), y, x + (r / 2), y, q, w, e);

	}


	if (A == "Uarrow")
	{
		drawLine2(x , y - r, x, y + r, q, w, e);
		drawLine(x - r, y, x, y + r, q, w, e);
		drawLine(x, y + r, x + r, y, q, w, e);

	}
	if (A == "Barrow")
	{
		drawLine2(x, y - r, x, y + r, q, w, e);
		drawLine(x - r, y, x, y - r, q, w, e);
		drawLine(x, y - r, x + r, y, q, w, e);
	}
	if (A == "Larrow")
	{
		drawLine2(x - r, y, x + r, y, q, w, e);
		drawLine(x - r, y, x, y + r, q, w, e);
		drawLine(x - r, y, x, y - r, q, w, e);
	}
	if (A == "Rarrow")
	{
		drawLine2(x - r, y, x + r, y, q, w, e);
		drawLine(x, y + r, x + r, y, q, w, e);
		drawLine(x, y - r, x + r, y, q, w, e);
	}

}
