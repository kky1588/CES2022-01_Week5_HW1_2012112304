#include "box.h"

void Box::draw()
{
	drawBox(center_x, center_y, radius, q, w, e);
}


void Box::drawBox(int x, int y, int r, float q, float w, float e)
{
	drawLine2(x - r, y - r, x - r, y + r, q, w, e);
	drawLine2(x - r, y + r, x + r, y + r, q, w, e);
	drawLine2(x - r, y - r, x + r, y - r, q, w, e);
	drawLine2(x + r, y - r, x + r, y + r, q, w, e);
}

bool Box::isInsideBox(double x, double y, int a, int b, int r)
{

	if ((a - r <= x) && (x <= a + r) && (b - r <= y) && (y <= b + r)) return true;
	else	return false;


}