#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)

    #define SPRINTF_LENGTH(format, ...) _scprintf(format, ##__VA_ARGS__)
    #define VPRINTF_LENGTH(format, args) _vscprintf(format, args)

    #define SPRINTF_SAFE(buffer, length, format, ...) sprintf_s(buffer, length, format, ##__VA_ARGS__)
    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf_s(buffer, length, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_s(timedata, currtime)
#else
    #define EXPORT

    #define SPRINTF_LENGTH(format, ...) snprintf(NULL, 0, format, ##__VA_ARGS__)
    #define VPRINTF_LENGTH(format, args) vsnprintf(NULL, 0, format, args)

    #define SPRINTF_SAFE(buffer, length, format, ...) sprintf(buffer, format, ##__VA_ARGS__)
    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf(buffer, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_r(currtime, timedata);
#endif

#endif
