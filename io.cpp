#include <GLFW/glfw3.h>

#include "io.h"

namespace io
{
	glm::vec2 last_click = glm::vec2(-INFINITY, -INFINITY);

	glm::vec2 get_last_click() {

		return last_click;
	}

	void set_last_click(double wx, double wy) {

		last_click = glm::vec2(wx, wy);
	}

	void GetWorldCoords(double x_ndc, double y_ndc, glm::mat4 translation, double* wx, double* wy) {

		glm::mat4 inverse = glm::inverse(translation);

		glm::vec4 pos_ndc = glm::vec4(x_ndc, y_ndc, 0.0, 1.0);

		glm::vec4 pos_world = inverse*pos_ndc;

		*wx = pos_world.x;
		*wy = pos_world.y;
	}

	void to_ndc(double xpos, double ypos, double* x_ndc, double* y_ndc, int WIDTH, int HEIGHT) {

		*x_ndc = xpos / WIDTH - 1;
		*y_ndc = ypos / HEIGHT - 1;
	}
}