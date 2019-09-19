#ifndef SLVN_CORE_H
#define SLVN_CORE_H

#ifdef SLVN_EXPORTS
	#define SLVN_API __declspec(dllexport)
#else
	#define SLVN_API __declspec(dllimport)
#endif

#define SLVN_RESULT int
#define SLVN_OK 0
#define SLVN_UNEXPECTED_RESULT -1

#endif