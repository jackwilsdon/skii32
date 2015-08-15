#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#ifdef _WIN32
	#ifdef logger_EXPORTS
		#define EXPORT __declspec(dllexport)
	#else
		#define EXPORT __declspec(dllimport)
	#endif
#else
	#define EXPORT
#endif

#endif