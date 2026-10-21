#include "types.h"

extern "C" s32 func_0045F628(const char *s) {
    s32 n;
    if (!s)
        return 0;
    n = 1;
    for (; *s; s++)
        if (*s == '\n')
            n++;
    return n;
}
