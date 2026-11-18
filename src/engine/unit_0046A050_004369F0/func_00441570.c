#include "types.h"
s32 func_0043DEF0(s32 *a);
s32 func_00441570(char *arg0) {
    s32 *p = (s32 *)(arg0 + 0x14);
    if ((*p ^ 7) == 0) return func_0043DEF0(p) + 4;
    return 0;
}
