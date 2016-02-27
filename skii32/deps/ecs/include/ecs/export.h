
#ifndef ECS_EXPORT_H
#define ECS_EXPORT_H

#ifdef ECS_STATIC_DEFINE
#  define ECS_EXPORT
#  define ECS_NO_EXPORT
#else
#  ifndef ECS_EXPORT
#    ifdef ecs_EXPORTS
        /* We are building this library */
#      define ECS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ECS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ECS_NO_EXPORT
#    define ECS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ECS_DEPRECATED
#  define ECS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ECS_DEPRECATED_EXPORT
#  define ECS_DEPRECATED_EXPORT ECS_EXPORT ECS_DEPRECATED
#endif

#ifndef ECS_DEPRECATED_NO_EXPORT
#  define ECS_DEPRECATED_NO_EXPORT ECS_NO_EXPORT ECS_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define ECS_NO_DEPRECATED
#endif

#endif
