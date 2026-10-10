#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00412EF8(void *, s32);             /* extern */
s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9800[];
struct func_00410F10_arg0 {
    s32 unk0;
    char pad4[0x64];
    s32 unk68;
};

void func_00410F10(void *arg0, s32 arg1) {
    s32 temp_v1;

    ((struct func_00410F10_arg0 *)arg0)->unk68 = (s32)D_005D9800;
    temp_v1 = ((struct func_00410F10_arg0 *)arg0)->unk0;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    func_00412EF8(arg0 + 0x24, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
