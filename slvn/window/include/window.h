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

void stderr_printf(const char* err, ...)
{
	va_list ap;
	va_start(ap, err);
	vfprintf(stderr, err, ap);
	va_end(ap);
}

typedef struct
{
	GLFWwindow* glfw_window;
	int width;
	int height;

} slvn_window;


// Start the systems required for creating a windows
void start();

// Create a new window
// This method also sets the OpenGL context current so OpenGL functions are available
void create_window(	slvn_window* window,
					int width,
					int height,
					const char* title,
					GLFWmonitor* monitor,
					GLFWwindow* share);

// Allow to set a custom window hint for opengl version
void set_window_hint(slvn_window* window, int major, int minor);

// Assume that we want to destroy the entire window and everything dependant on it
void destroy(slvn_window* window);

#endif // SLVN_WINDOW_H