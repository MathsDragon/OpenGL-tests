#include <GLFW\glfw3.h>
#include "limath.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Square.h"

void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

int main(void)
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	//glfwSetKeyCallback(window, keyCallBack);
	glfwSetScrollCallback(window, scroll_callback);
	Square square(0, 0);
	double halfside = 0.1;
	int r = 255;
	int g = 255;
	int b = 255;
	while (!glfwWindowShouldClose(window)) {
		//Setup View
		float x = 0;
		float y = 0;
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Swap buffer and check for events
		
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			y += 1;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			y -= 1;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			x -= 1;
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			x += 1;
		}

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			square.increaseSpeed();
		}
		square.update(x, y);
		glColor3d(r,g,b);
		glBegin(GL_POLYGON);

		glVertex2d(square.getx() + halfside, square.gety() + halfside);
		glVertex2d(square.getx() + halfside, square.gety() - halfside);
		glVertex2d(square.getx() - halfside, square.gety() - halfside);
		glVertex2d(square.getx() - halfside, square.gety() + halfside);

		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();


	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void keyCallBack(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	

	if (key == GLFW_KEY_SPACE)
	{
		switch (action)
		{
		case GLFW_PRESS:
			std::cout << "Been pressed" << std::endl;
			break;
		case GLFW_REPEAT:
			std::cout << "Held" << std::endl;
			break;
		case GLFW_RELEASE:
			std::cout << "Released" << std::endl;
			break;
		default:
			break;
		}
		
	}
}

void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	changeColour(r);
}
