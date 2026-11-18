#include "types.h"
s32 func_004AC7B8(void **arg0) {
    s32 n = 0;
    void **p = (void **)*arg0;
    while (p != 0) {
        p = (void **)p[2];
        n++;
    }
    return n;
}
