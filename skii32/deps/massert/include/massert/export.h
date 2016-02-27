
#ifndef MASSERT_EXPORT_H
#define MASSERT_EXPORT_H

#ifdef MASSERT_STATIC_DEFINE
#  define MASSERT_EXPORT
#  define MASSERT_NO_EXPORT
#else
#  ifndef MASSERT_EXPORT
#    ifdef massert_EXPORTS
        /* We are building this library */
#      define MASSERT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MASSERT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MASSERT_NO_EXPORT
#    define MASSERT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MASSERT_DEPRECATED
#  define MASSERT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MASSERT_DEPRECATED_EXPORT
#  define MASSERT_DEPRECATED_EXPORT MASSERT_EXPORT MASSERT_DEPRECATED
#endif

#ifndef MASSERT_DEPRECATED_NO_EXPORT
#  define MASSERT_DEPRECATED_NO_EXPORT MASSERT_NO_EXPORT MASSERT_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define MASSERT_NO_DEPRECATED
#endif

#endif
