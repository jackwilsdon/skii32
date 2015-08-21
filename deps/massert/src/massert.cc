#include "massert/massert.h"

#include <cstdio>
#include <cstdlib>

MAsserter::MAsserter() : MAsserter(nullptr) {}
MAsserter::MAsserter(char *progname) : progname(progname) {}

void MAsserter::assert(const char *assertion, const char *message, const char *file, unsigned int line, const char *function) {
    if (progname != NULL) {
        fprintf(stderr, "%s: %s:%d: %s:\n", progname, file, line, function);
    } else {
        fprintf(stderr, "%s:%d: %s:\n", file, line, function);
    }

    fprintf(stderr, "Assertion `%s' failed: %s\n", assertion, message);
    printf("Aborted\n");
    std::exit(EXIT_FAILURE);
}

MAsserter _global_masserter;
