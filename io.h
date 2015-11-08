#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace io
{
	glm::vec2 get_last_click();

	void set_last_click(double wx, double wy);

	void GetWorldCoords(double xpos, double ypos, glm::mat4 translation, double* wx, double* wy);

	void to_ndc(double xpos, double ypos, double* x_ndc, double* y_ndc, int WIDTH, int HEIGHT);
}

#endif
