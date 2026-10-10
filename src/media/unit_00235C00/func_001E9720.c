#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E94D8();
s32 func_00206DD8(s32);
s32 func_0020D718(s32);
s32 func_001E9720(void) {
    s32 res = 0;
    s32 p = func_001E94D8();
    while (p != 0) {
        if (func_0020D718(p) != 0) res = p;
        p = func_00206DD8(p);
    }
    return res;
}
