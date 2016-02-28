#ifndef LOGGER_PLATFORM_H
#define LOGGER_PLATFORM_H

#ifdef _WIN32
    #define VPRINTF_LENGTH(format, args) _vscprintf(format, args)

    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf_s(buffer, length, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_s(timedata, currtime)
#else
    #define VPRINTF_LENGTH(format, args) vsnprintf(NULL, 0, format, args)

    #define VSPRINTF_SAFE(buffer, length, format, args) vsprintf(buffer, format, args)

    #define LOCALTIME_SAFE(timedata, currtime) localtime_r(currtime, timedata);
#endif

#endif
