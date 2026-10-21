#include "types.h"
extern char D_00585A30[];
s32 func_0040B980(char *a);
s32 func_0040EDE0(char *arg0, s64 arg1) {
    if (func_0040B980(D_00585A30) == 0) return 0;
    *(s64 *)(arg0 + 0xA8) = arg1;
    return 1;
}
