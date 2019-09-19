#ifndef SLVN_DEBUG_H
#define SLVN_DEBUG_H

#include <stdarg.h>
#include <stdio.h>

#ifndef NDEBUG
#	define SLVN_PRINT(content) stderr_printf(content)
#else
#	define SLVN_PRINT(content) (void)0
#endif

#endif