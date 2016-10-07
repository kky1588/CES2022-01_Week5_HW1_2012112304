#include "GeometricObject.h"
#include "box.h"
#include "circle.h"
#include "inicon.h"

GeometricObject *my_Object = new GeometricObject;
GeometricObject *my_Circle = new Circle;

int width= my_Object->width ;
int height= my_Object->height;
float* pixels = my_Object->pixels;

double xpos, ypos;

void drawOnPixelBuffer()
{
	// Make Background white
	my_Object->whitebg(pixels, width, height);


	//############# (Problem4) ###########
	// Draw Boxes and Make mouse effect for circles 
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			// Draw Boxes
			my_Object->drawBox(102 + 205 * i, 128 + 256 * j, 80, 0.0f, 0.0f, 1.0f);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			if (my_Object->isInsideBox(xpos, ypos, 102 + 205 * i, 128 + 256 * (3 - j), 80) == true)
			{
				my_Object->drawBox(102 + 205 * i, 128 + 256 * j, 80, 0.0f, 1.0f, 0.0f);
			}
	}

	
	/*
	//############# (Problem3) ###########
	// Draw Circles and  Make mouse effect for circles 
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			// Draw Circles
			my_Object->drawCircle(102 + 205 * i, 128 + 256 * j, 100, 5, 1.0f, 0.0f, 0.0f);

			//############# (Problem2) ###########
			// Draw another circles around circles
			my_Object->drawCircle(102 + 205 * i, 128 + 256 * j, 80, 6, 1.0f, 0.0f, 0.0f);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		if (my_Object->isInsideCircle(xpos, ypos, 102 + 205 * i, 128 + 256 * (3-j), 100) == true)
		{
			my_Object->drawCircle(102 + 205 * i, 128 + 256 * j, 100, 5, 0.0f, 1.0f, 0.0f);
		}
	}
	*/



	//############# (Problem1) ###########
	// Draw icons inside the 20 borders
	for (int j = 1; j<4; j+=2)
	{
		my_Object->drawMinicon("thickline", 102 , 128 + 256 * j,40, 1.0f, 0.0f, 0.0f);
		my_Object->drawCircle(102 + 205 * 1, 128 + 256 * j, 40, 6, 1.0f, 0.0f, 0.0f);
		my_Object->drawBox(102 + 205 * 2, 128 + 256 * j, 40, 1.0f, 0.0f, 0.0f);
		my_Object->drawMinicon("X", 102 + 205 * 3, 128 + 256 * j, 40, 1.0f, 0.0f, 0.0f);
		my_Object->drawMinicon("Barrow", 102 + 205 * 4, 128 + 256 * j, 50, 1.0f, 0.0f, 0.0f);

		my_Object->drawMinicon("Rarrow", 102 + 205 * 0, 128 + 256 * (j-1), 50, 1.0f, 0.0f, 0.0f);
		my_Object->drawMinicon("A", 102 + 205 * 1, 128 + 256 * (j - 1), 50, 1.0f, 0.0f, 0.0f);
		my_Object->drawLine2(102 + 205 * 2, 128 + 256 * (j - 1)-40, 102 + 205 * 2, 128 + 256 * (j - 1) +40, 1.0f, 0.0f, 0.0f);
		my_Object->drawMinicon("Larrow", 102 + 205 * 3, 128 + 256 * (j - 1), 50, 1.0f, 0.0f, 0.0f);
		my_Object->drawMinicon("Uarrow", 102 + 205 * 4, 128 + 256 * (j - 1), 50, 1.0f, 0.0f, 0.0f);
	}
	
}


int main(void)
{
	GLFWwindow* window;



	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Problem 4", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop unt il the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);
		glfwGetCursorPos(window, &xpos, &ypos);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	delete[] pixels;

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}