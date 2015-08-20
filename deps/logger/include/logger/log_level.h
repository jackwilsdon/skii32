#ifndef _LOG_MESSAGE_H_
#define _LOG_MESSAGE_H_

#include <string>

#include "logger/platform.h"

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

EXPORT std::string LogLevel_name(LogLevel level, bool sentence_case = true);

#endif
