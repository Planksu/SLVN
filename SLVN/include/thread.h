#ifndef SLVN_THREAD_H
#define SLVN_THREAD_H

#include <core.h>
#include <debug.h>
#include <windows.h>
#include <strsafe.h>
#include <stdlib.h>

typedef struct
{
	DWORD		thread_id;
	HANDLE		handle;
} slvn_thread;

SLVN_EXTERN_BEGIN
SLVN_RESULT		SLVN_API	slvn_thread_create(slvn_thread* thread, void* entry);
SLVN_RESULT		SLVN_API	slvn_thread_wait(slvn_thread* thread);
SLVN_RESULT		SLVN_API	slvn_threads_wait(slvn_thread** threads, int count);
SLVN_EXTERN_END

#endif