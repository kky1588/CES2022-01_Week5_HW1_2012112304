#include "inicon.h"

void Icon::draw(char A[20])
{
	drawMinicon(A, center_x, center_y, radius, q, w, e);
}

// You can draw some icons probably be inside the big icon. 
// (x, y) is center of icon, and r will be radius.

void Icon::drawMinicon(char A[20], int x, int y, int r, float q, float w, float e)
{
	if (A == "thickline")
	{
		drawLine(x-r, y-r, x +  r, y + r, q, w, e);
		drawLine(x -r- 1, y-r, x + r + 1, y + r + 1, q, w, e);
		drawLine(x-r, y-r - 1, x + r + 1, y +  r, q, w, e);

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
		drawLine2(x, y - r, x, y + r, q, w, e);
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
