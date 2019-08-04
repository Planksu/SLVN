#include "window.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	slvn_window window = { 0 };
	start(&window);
	create_window(&window, 640, 480);

	while (!glfwWindowShouldClose(window.glfw_window))
	{
		update(&window);
	}

	destroy(&window);
	return 0;
}