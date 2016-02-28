#ifndef LOGGER_LEVEL_H
#define LOGGER_LEVEL_H

#include <string>

#include "logger/export.h"

namespace logger {
    enum class Level {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    LOGGER_EXPORT std::string GetLevelName(Level level, bool sentence_case = true);
}

#endif
