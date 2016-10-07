#pragma once
#include "GeometricObject.h"

class Icon : public GeometricObject
{
public:
	char A[20];
	int center_x, center_y, radius;
	float q, w, e;
	void draw(char A[20]);
	void drawMinicon(char A[20], int x, int y, int r, float q, float w, float e);

};



