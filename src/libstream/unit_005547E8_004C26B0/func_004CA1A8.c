#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CA568(s32, void *);                 /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB328[];
struct func_004CA1A8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC8];
    s32 unkD0;
};

void func_004CA1A8(struct func_004CA1A8_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unkD0 = (s32)D_005DB328;
    temp_v1 = arg0->unk4;
    if (temp_v1 != 0) {
        func_004CA568(temp_v1, arg0);
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
