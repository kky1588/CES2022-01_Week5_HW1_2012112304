#pragma once
#include "GeometricObject.h"

class Box : public GeometricObject
{
public:

	int center_x, center_y, radius;
	float q, w, e;
	// function for drawing circle 

	Box::Box()
	{
		center_x = 1, center_y = 1, radius =1;
		q =0, w=0, e=0;
		draw();
	}

	void draw();
	void drawBox(int x, int y, int r, float q, float w, float e);
	bool isInsideBox(double x, double y, int a, int b, int r);
};