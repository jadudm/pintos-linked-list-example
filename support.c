#include <stdio.h>
#include "support.h"

void
debug_panic (const char *file, int line, const char *function,
             const char *message, ...)
{
      printf ("PANIC at %s:%d in %s(): ", file, line, function);
}
