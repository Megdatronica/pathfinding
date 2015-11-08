//Include GLEW
#include <gl/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//OpenGL maths library
#include <glm/glm.hpp>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//IO utilities
#include "io.h"
#include "main.h"

//Declare a window object
GLFWwindow* window;

//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Mouse button click callback
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

	//Print which button was pressed
	printf("%d\n", button);

	//Mouse position
	double xpos, ypos, x_ndc, y_ndc, wx, wy = 0.0;

	// get current mouse pos
	glfwGetCursorPos(window, &xpos, &ypos);

	int width, height;
	glfwGetWindowSize(window, &width, &height);

	io::to_ndc(xpos, ypos, &x_ndc, &y_ndc, width, height);

	io::GetWorldCoords(x_ndc, y_ndc, glm::translate(glm::vec3(10.0, 0.0, 0.0)), &wx, &wy);

	// If the last click is not set, it takes the value (-INFINITY, -INFINITY)
	// and so we test to see if the x value is -INFINITY.

	if (io::get_last_click().x == -INFINITY) {

		io::set_last_click(wx, wy);
	}
	else {
		//Do path finding...
	}
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Create a window and create its OpenGL context
	window = glfwCreateWindow(700, 700, "Test Window", NULL, NULL);

	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//If the window couldn't be created
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(window);

	//Sets the key callback
	glfwSetKeyCallback(window, key_callback);

	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}


	//Set a background color
	glClearColor(0.0f, 0.1f, 0.7f, 0.0f);


	//Main Loop
	do
	{
		//Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		//Swap buffers
		glfwSwapBuffers(window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...
		glfwPollEvents();

	} //Check if the ESC key had been pressed or if the window had been closed
	while (!glfwWindowShouldClose(window));

	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(window);
	//Finalize and clean up GLFW
	glfwTerminate();

	exit(EXIT_SUCCESS);
}
