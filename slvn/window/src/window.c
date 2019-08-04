#include "window.h"

void start()
{
	if (!glfwInit())
	{
		SLVN_PRINT("SLVN_WINDOW: Couldn't initialize glfw correctly.");
	}
}

void create_window(slvn_window* window, int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	window->glfw_window = glfwCreateWindow(width, height, title, monitor, share);

	if (!window->glfw_window)
	{
		SLVN_PRINT("SLVN_WINDOW: Window or OpenGL context creation failed.");
	}
}

void set_window_hint(slvn_window* window, int major, int minor)
{

}

