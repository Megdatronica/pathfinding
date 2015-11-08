#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace io
{
	// Returns the last_click position
	glm::vec2 get_last_click();

	// Sets the last_click position
	void set_last_click(double wx, double wy);

	// Calculates the world coordinate position of a mouse click at (xpos, ypos)
	// given the camera position corresponding to a view*projection matrix.
	void GetWorldCoords(double xpos, double ypos, glm::mat4 VPmatrix, double* wx, double* wy);

	// Helper function that takes screen coordinates and calculates the corresponding
	// Normalised Device Coordinates.
	void to_ndc(double xpos, double ypos, double* x_ndc, double* y_ndc, int WIDTH, int HEIGHT);
}

#endif
