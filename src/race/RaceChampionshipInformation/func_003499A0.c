#include "types.h"
s32 func_003499A0(char *arg0) {
    s32 lim = *(s32 *)(arg0 + 0x318);
    char *p = arg0 + 0x4B8;
    s32 i = 1;
    do {
        if (*(s32 *)p >= lim) return 0;
        p += 0x1A0;
        i++;
    } while (i < 6);
    return 1;
}
