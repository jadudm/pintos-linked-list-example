#ifndef __SUPPORT
#define __SUPPORT

#define UNUSED __attribute__ ((unused))
#define NO_RETURN __attribute__ ((noreturn))
#define NO_INLINE __attribute__ ((noinline))
#define PRINTF_FORMAT(FMT, FIRST) __attribute__ ((format (printf, FMT, FIRST)))

#define PANIC(...) debug_panic (__FILE__, __LINE__, __func__, __VA_ARGS__)

/* This is outside the header guard so that debug.h may be
   included multiple times with different settings of NDEBUG. */
#undef ASSERT
#undef NOT_REACHED

#ifndef NDEBUG
#define ASSERT(CONDITION)                                       \
        if (CONDITION) { } else {                               \
                PANIC ("assertion `%s' failed.", #CONDITION);   \
        }
#define NOT_REACHED() PANIC ("executed an unreachable statement");
#else
#define ASSERT(CONDITION) ((void) 0)
#define NOT_REACHED() for (;;)
#endif /* lib/debug.h */

#endif /* __SUPPORT */
