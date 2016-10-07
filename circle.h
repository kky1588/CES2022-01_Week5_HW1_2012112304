#pragma once
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:


	int center_x, center_y, radius, thick;
	float q, w, e;

	Circle :: Circle()
	{
		center_x=1, center_y=1, radius=1, thick=1;
		q=1, w=1, e=1;
		draw();
	}

	void Circle::draw();
	void Circle::drawCircle(int center_x, int center_y, int radius, int thick, float q, float w, float e);
	bool Circle::isInsideCircle(double x, double y, int a, int b,int r);

};


