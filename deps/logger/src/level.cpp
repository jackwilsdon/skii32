#include "logger/level.h"

namespace logger {
    std::string GetLevelName(Level level, bool sentenceCase) {
        switch (level) {
            case Level::DEBUG:
                return sentenceCase ? "Debug" : "DEBUG";
            case Level::INFO:
                return sentenceCase ? "Info" : "INFO";
            case Level::WARN:
                return sentenceCase ? "Warn" : "WARN";
            case Level::ERROR:
                return sentenceCase ? "Error" : "ERROR";
            case Level::FATAL:
                return sentenceCase ? "Fatal" : "FATAL";
        }
    }
}
