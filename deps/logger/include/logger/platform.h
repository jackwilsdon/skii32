#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#ifdef _WIN32
    #ifdef logger_EXPORTS
        #define EXPORT __declspec(dllexport)
    #else
        #define EXPORT __declspec(dllimport)
    #endif

    #define VPRINTF_LENGTH(format, args) _vscprintf(format, args)
    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf_s(buffer, length, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_s(timedata, currtime)
#else
    #define EXPORT

    #define VPRINTF_LENGTH(format, args) vsnprintf(NULL, 0, format, args)
    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf(buffer, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_r(currtime, timedata);
#endif

#endif
