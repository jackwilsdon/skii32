#include <cstdlib>

#include "logger/logger.h"

int main(int argc, char *argv[]) {
    logger::Logger l;

    l.log(logger::Level::DEBUG, "Debug");
    l.log(logger::Level::INFO, "Information");
    l.log(logger::Level::WARN, "Warning");
    l.log(logger::Level::ERROR, "Error");
    l.log(logger::Level::FATAL, "Fatal");

    return EXIT_SUCCESS;
}
