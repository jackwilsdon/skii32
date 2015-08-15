#include "logger/log_level.h"

std::string LogLevel_name(LogLevel level, bool sentence_case) {
   switch (level) {
   case LogLevel::DEBUG:
       return sentence_case ? "Debug" : "DEBUG";
   case LogLevel::INFO:
       return sentence_case ? "Info" : "INFO";
   case LogLevel::WARN:
       return sentence_case ? "Warn" : "WARN";
   case LogLevel::ERROR:
       return sentence_case ? "Error": "ERROR";
   case LogLevel::FATAL:
       return sentence_case ? "Fatal" : "FATAL";
   }

   return "";
}
