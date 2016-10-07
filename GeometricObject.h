#pragma once
#include <glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <time.h>
#include <stdbool.h>
#include <iostream>


class GeometricObject
{
public:
	int		width = 1024;
	int		height = 1024;
	float*	pixels = new float[width*height * 3];

	void	whitebg(float* pixels, int width, int height);
	double	getRandomNumber(const double min, const double max);
	void	drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
	void	drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
	void	drawLine2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
	void	drawCircle(int center_x, int center_y, int radius, int thick, float q, float w, float e);
	bool	isInsideCircle(double x, double y, int a, int b, int r);
	void	drawBox(int x, int y, int r, float q, float w, float e);
	bool	isInsideBox(double x, double y, int a, int b, int r);
	void	drawMinicon(char A[20], int x, int y, int r, float q, float w, float e);
};