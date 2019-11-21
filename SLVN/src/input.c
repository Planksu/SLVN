#include <input.h>

SLVN_RESULT slvn_input_get_async_key(SLVN_KEYCODE keycode)
{
	return GetAsyncKeyState(keycode);
}