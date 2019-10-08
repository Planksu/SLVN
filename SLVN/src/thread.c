#include <thread.h>

SLVN_RESULT slvn_thread_create(slvn_thread** thread, void* entry)
{
	if (thread == NULL)
	{
		return SLVN_UNEXPECTED_RESULT;
	}

	*thread = CreateThread(	NULL,
									0,
									entry,
									NULL,
									0,
									NULL);

	if (*thread == NULL)
	{
		return SLVN_UNEXPECTED_RESULT;
	}
	return SLVN_OK;
}

SLVN_RESULT slvn_thread_wait(slvn_thread* thread)
{
	switch (WaitForSingleObject((HANDLE)thread, INFINITE))
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
	switch (WaitForMultipleObjects(count, threads, TRUE, INFINITE))
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