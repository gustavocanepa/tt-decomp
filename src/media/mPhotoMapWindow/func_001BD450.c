#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_001BD180();                              /* extern */

struct func_001BD450_temp_v0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_001BD450(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct func_001BD450_temp_v0 *temp_v0;

    temp_v0 = func_001BD180();
    return (s32) (temp_v0->unk8 - temp_v0->unk4) >> 4;
}
