#include "window.h"

void stderr_printf(const char* err, ...)
{
	va_list ap;
	va_start(ap, err);
	vfprintf(stderr, err, ap);
	va_end(ap);
}


void start()
{
	if (!glfwInit())
	{
		SLVN_PRINT("SLVN_WINDOW: Couldn't initialize glfw correctly.");
	}
}

void create_window_with_monitor(slvn_window* window, int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	window->width = width;
	window->height = height;
	window->glfw_window = glfwCreateWindow(width, height, title, monitor, share);

	if (!window->glfw_window)
	{
		SLVN_PRINT("SLVN_WINDOW: Window or OpenGL context creation failed.");
		exit(-1);
	}
	_make_context_current(window);
}

void create_window_with_monitor_and_hints(slvn_window* window, int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share, int major, int minor)
{
	window->width = width;
	window->height = height;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	window->glfw_window = glfwCreateWindow(width, height, title, monitor, share);

	if (!window->glfw_window)
	{
		SLVN_PRINT("SLVN_WINDOW: Window or OpenGL context creation failed.");
		exit(-1);
	}
	_make_context_current(window);
}

void create_window_with_hints(slvn_window* window, int width, int height, int major, int minor)
{
	window->width = width;
	window->height = height;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	window->glfw_window = glfwCreateWindow(width, height, "slvn_window", NULL, NULL);

	if (!window->glfw_window)
	{
		SLVN_PRINT("SLVN_WINDOW: Window or OpenGL context creation failed.");
		exit(-1);
	}
	_make_context_current(window);
}

void create_window(slvn_window* window, int width, int height)
{
	window->width = width;
	window->height = height;
	window->glfw_window = glfwCreateWindow(width, height, "slvn_window", NULL, NULL);

	if (!window->glfw_window)
	{
		SLVN_PRINT("SLVN_WINDOW: Window or OpenGL context creation failed.");
		exit(-1);
	}
	_make_context_current(window);
}

void update(slvn_window* window)
{
	glfwPollEvents();
	glfwSwapBuffers(window);
	window->time = glfwGetTime();
}

void destroy(slvn_window* window)
{
	glfwTerminate();
}

void _make_context_current(slvn_window* window)
{
	glfwMakeContextCurrent(window->glfw_window);
}