#ifndef SLVN_INPUT_H
#define SLVN_INPUT_H

#include <core.h>
#include <debug.h>
#include <WinUser.h>

typedef enum
{
	SLVN_LMOUSE = VK_LBUTTON,
	SLVN_RMOUSE = VK_RBUTTON,
	SLVN_CANCEL = VK_CANCEL,
	SLVN_MMOUSE = VK_MBUTTON,
	SLVN_BACK = VK_BACK,
	SLVN_TAB = VK_TAB,
	SLVN_CLEAR = VK_CLEAR,
	SLVN_SHIFT = VK_SHIFT,
	SLVN_CONTROL = VK_CONTROL,
	SLVN_ALT = VK_MENU,
	SLVN_PAUSE = VK_PAUSE,
	SLVN_CAPS = VK_CAPITAL,
	SLVN_ESC = VK_ESCAPE,
	SLVN_SPACE = VK_SPACE,
	SLVN_PGUP = VK_PRIOR,
	SLVN_PGDOWN = VK_NEXT,
	SLVN_END = VK_END,
	SLVN_HOME = VK_HOME,
	SLVN_LEFT = VK_LEFT,
	SLVN_UP = VK_UP,
	SLVN_RIGHT = VK_RIGHT,
	SLVN_DOWN = VK_DOWN,
	SLVN_SELECT = VK_SELECT,
	SLVN_PRINT = VK_PRINT,
	SLVN_INSERT = VK_INSERT,
	SLVN_DELETE = VK_DELETE,
	SLVN_LSHIFT = VK_LSHIFT,
	SLVN_RSHIFT = VK_RSHIFT,

	SLVN_0 = 0x30,
	SLVN_1 = 0x31,
	SLVN_2 = 0x32,
	SLVN_3 = 0x33,
	SLVN_4 = 0x34,
	SLVN_5 = 0x35,
	SLVN_6 = 0x36,
	SLVN_7 = 0x37,
	SLVN_8 = 0x38,
	SLVN_9 = 0x39,
	SLVN_A = 0x41,
	SLVN_B = 0x42,
	SLVN_C = 0x43,
	SLVN_D = 0x44,
	SLVN_E = 0x45,
	SLVN_F = 0x46,
	SLVN_G = 0x47,
	SLVN_H = 0x48,
	SLVN_I = 0x49,
	SLVN_J = 0x4A,
	SLVN_K = 0x4B,
	SLVN_L = 0x4C,
	SLVN_M = 0x4D,
	SLVN_N = 0x4E,
	SLVN_O = 0x4F,
	SLVN_P = 0x50,
	SLVN_Q = 0x51,
	SLVN_R = 0x52,
	SLVN_S = 0x53,
	SLVN_T = 0x54,
	SLVN_I = 0x55,
	SLVN_V = 0x56,
	SLVN_W = 0x57,
	SLVN_X = 0x58,
	SLVN_Y = 0x59,
	SLVN_Z = 0x5A,

} SLVN_KEYCODE;

SLVN_EXTERN_BEGIN
		SLVN_API	slvn_input_get_async_key(SLVN_KEYCODE keycode);
SLVN_EXTERN_END



#endif // SLVN_INPUT_H