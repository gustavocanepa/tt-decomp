#include "types.h"
extern char D_00585A30[];
char **func_0040BA50(char *a, s32 b);
s32 func_004103A8(s32 arg0) {
    char **p = func_0040BA50(D_00585A30, arg0);
    if (p == 0) return -1;
    return *(s32 *)(*p + 4);
}
