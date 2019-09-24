#ifndef SLVN_WINDOW_H
#define SLVN_WINDOW_H

#include <core.h>
#include <debug.h>
#include <windows.h>


typedef struct
{
	int width;
	int height;
	char* title;
	HWND hwnd;
	WNDCLASSW wc;
} slvn_window;

SLVN_EXTERN_BEGIN
SLVN_RESULT		SLVN_API	slvn_window_initialize(slvn_window* window, int width, int height);
SLVN_RESULT		SLVN_API	slvn_window_update(slvn_window* window);
void			SLVN_API	slvn_window_wait(slvn_window* window);
void			SLVN_API	slvn_window_poll(slvn_window* window);
LRESULT			CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
SLVN_EXTERN_END

#endif 