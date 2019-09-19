#include <window.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam) {

	switch (msg) {

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

SLVN_RESULT slvn_window_initialize(slvn_window* window, int width, int height)
{
	// Perhaps some way to avoid registering window class twice?

	window->wc.style = 0;
	window->wc.lpfnWndProc = WndProc;
	window->wc.cbClsExtra = 0;
	window->wc.cbWndExtra = 0;
	window->wc.hInstance = GetModuleHandle(0);
	window->wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	window->wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	window->wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	window->wc.lpszMenuName = NULL;
	window->wc.lpszClassName = L"slvn_window";

	//No window classes registered by a DLL are unregistered when the DLL is unloaded. 
	//A DLL must explicitly unregister its classes when it is unloaded.

	if (RegisterClassW(&window->wc) == 0)
	{
		return SLVN_UNEXPECTED_RESULT;
	}

	window->hwnd = CreateWindowW(window->wc.lpszClassName,
		L"slvn_window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(0),
		NULL);

	ShowWindow(window->hwnd, GetCommandLineW());

	return SLVN_OK;
}

SLVN_RESULT slvn_window_update(slvn_window* window)
{
	if (UpdateWindow(window->hwnd) == 0)
	{
		return SLVN_UNEXPECTED_RESULT;
	}
	return SLVN_OK;
}

void slvn_window_wait(slvn_window* window)
{
	MSG msg;
	while (GetMessage(&msg, window->hwnd, 0, 0))
	{
		DispatchMessage(&msg);
	}
}

void slvn_window_poll(slvn_window* window)
{
	MSG msg;
	while (PeekMessage(&msg, window->hwnd, 0, 0, PM_REMOVE))
	{
		DispatchMessage(&msg);
	}
}

