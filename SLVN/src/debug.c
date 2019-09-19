#include <debug.h>

void stderr_printf(const char* err, ...)
{
	va_list ap;
	va_start(ap, err);
	vfprintf(stderr, err, ap);
	va_end(ap);
}
