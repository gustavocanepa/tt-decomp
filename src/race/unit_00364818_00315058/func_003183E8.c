#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003183E8(s32 *arg0, s32 *arg1, s32 arg2) {
    *arg0 = 1;
    *arg1 = 1;
    if (arg2 < 0) {
        *arg1 = -arg2;
        return;
    }
    if (arg2 > 0) {
        *arg0 = arg2;
    }
}
