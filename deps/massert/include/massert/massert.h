#ifndef _MASSERT_H_
#define _MASSERT_H_

#include "massert/export.h"

class MASSERT_EXPORT MAsserter {
public:
    MAsserter();
    MAsserter(char *progname);
    void assert(const char *assertion, const char *message, const char *file, unsigned int line, const char *function);

private:
    const char *progname;
};

extern MASSERT_EXPORT MAsserter _global_masserter;

#define massert_setup(argc, argv) (_global_masserter = (argc > 0) ? MAsserter(argv[0]) : MAsserter() )
#define massert(assertion, message) ((assertion) ? ((void) 0) : _global_masserter.assert(#assertion, message, __FILE__, __LINE__, __func__))

#endif
