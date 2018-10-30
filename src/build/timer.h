#ifndef NJAKSDTHASKJERAXJGFBZJDLAGZ
#define NJAKSDTHASKJERAXJGFBZJDLAGZ
#if defined (PM_TIMER_MSVC) || defined (PM_TIMER_CLOCK_GETTIME) || defined (PM_TIMER_GETRUSAGE) || defined (PM_TIMER_EXTERNAL) || defined (PM_TIMER_NONE)
#else
	#ifdef _MSC_VER
		#define PM_TIMER_MSVC
	#elif defined(__APPLE_CC__)
		#define PM_TIMER_GETRUSAGE
	#else
		#define PM_TIMER_CLOCK_GETTIME
	#endif
#endif
#ifdef PM_TIMER_MSVC
	#include <windows.h>
	inline double get_time()
	{
		LARGE_INTEGER t, frequency;
		QueryPerformanceCounter(&t);
		QueryPerformanceFrequency(&frequency);
		return (double)t.QuadPart/(double)frequency.QuadPart;
	}
#endif
#ifdef PM_TIMER_CLOCK_GETTIME
	#include <time.h>
	inline double get_time()
	{
		struct timespec t;
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
		return (double)t.tv_nsec*1.00E-9 + (double)t.tv_sec;
	}
#endif
#ifdef PM_TIMER_GETRUSAGE
	#include <sys/resource.h>
	inline double get_time()
	{
		struct rusage t;
		getrusage (RUSAGE_SELF, &t);
		return (double)t.ru_utime.tv_usec*1.00E-6 + (double)t.ru_utime.tv_sec;
	}
#endif
#ifdef PM_TIMER_EXTERNAL
	extern double get_time();
#endif
#ifdef PM_TIMER_NONE
	inline double get_time() { return 0; }
#endif
#endif
