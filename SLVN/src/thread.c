#include <thread.h>

SLVN_RESULT slvn_thread_create(slvn_thread* thread, void* entry)
{
	thread = (slvn_thread*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(slvn_thread));
	thread->handle = CreateThread(	NULL,
									0,
									entry,
									NULL,
									0,
									&thread->thread_id);

	if (thread->handle == NULL)
	{
		return SLVN_UNEXPECTED_RESULT;
	}
	return SLVN_OK;
}

SLVN_RESULT slvn_thread_wait(slvn_thread* thread)
{
	switch (WaitForSingleObject(thread->handle, INFINITE))
	{
	case WAIT_ABANDONED:
		return SLVN_UNEXPECTED_RESULT;
		break;
	case WAIT_FAILED:
		return SLVN_UNEXPECTED_RESULT;
		break;
	case WAIT_OBJECT_0:
		return SLVN_OK;
		break;
	default:
		return SLVN_UNEXPECTED_RESULT;
		break;
	}
}

SLVN_RESULT slvn_threads_wait(slvn_thread** threads, int count)
{
	HANDLE* handles = (HANDLE*)malloc(sizeof(HANDLE));
	
	int i = 1;
	while (threads != NULL)
	{
		handles = threads[i-1]->handle;
		i++;
		handles = realloc(handles, sizeof(HANDLE) * i);
	}
	switch (WaitForMultipleObjects(count, handles, TRUE, INFINITE))
	{
	case WAIT_ABANDONED_0:
		return SLVN_UNEXPECTED_RESULT;
		break;
	case WAIT_FAILED:
		return SLVN_UNEXPECTED_RESULT;
		break;
	case WAIT_OBJECT_0:
		return SLVN_OK;
		break;
	default:
		return SLVN_UNEXPECTED_RESULT;
		break;
	}
}