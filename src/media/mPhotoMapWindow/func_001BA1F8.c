#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001BA0A8();
s32 func_00206EF0(s32);
void func_001BA1F8(s32 arg0, s32 arg1) {
    s32 p;
    s32 i;
    p = func_001BA0A8();
    for (i = 0; p != 0 && i != arg1; i++) {
        p = func_00206EF0(p);
    }
}
