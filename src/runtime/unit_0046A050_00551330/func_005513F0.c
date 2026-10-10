#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00582A74[];
void func_005513F0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = 1 << arg0;
    temp_v0 = *(s32 *)(s32)D_00582A74 & ~temp_v1;
    *(s32 *)(s32)D_00582A74 = (arg1 != 0) ? (temp_v0 | temp_v1) : temp_v0;
}
