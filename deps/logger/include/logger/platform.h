#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#ifdef _WIN32
	#ifdef logger_EXPORTS
		#define EXPORT __declspec(dllexport)
	#else
		#define EXPORT __declspec(dllimport)
	#endif

	#define VSNPRINTF_SAFE(buffer, length, count, format, args) vsnprintf_s(buffer, length, count, format, args)
#else
	#define EXPORT
	
	#define VSNPRINTF_SAFE(buffer, length, count, format, args) vsnprintf(buffer, length, format, args)
#endif
#endif