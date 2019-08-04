#ifndef SLVN_WINDOW_H
#define SLVN_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef NDEBUG
#	define SLVN_PRINT(content) stderr_printf(content)
#else
#	define SLVN_PRINT(content) (void)0
#endif


typedef struct
{
	GLFWwindow* glfw_window;
	int width;
	int height;
	double time;
} slvn_window;


// Start the systems required for creating a windows
void start();

// Create a new window
// This method also sets the OpenGL context current so OpenGL functions are available
void create_window_with_monitor(	slvn_window* window,
					int width,
					int height,
					const char* title,
					GLFWmonitor* monitor,
					GLFWwindow* share);

void create_window_with_monitor_and_hints(	slvn_window* window,
					int width,
					int height,
					const char* title,
					GLFWmonitor* monitor,
					GLFWwindow* share,
					int major,
					int minor);

void create_window_with_hints(	slvn_window* window,
					int width,
					int height,
					int major,
					int minor);

void create_window(	slvn_window* window,
					int width,
					int height);

void update(slvn_window* window);

void _make_context_current(slvn_window* window);

// Assume that we want to destroy the entire window and everything dependant on it
void destroy(slvn_window* window);

#endif // SLVN_WINDOW_H