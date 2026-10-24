#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00202B70(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005A56B0[];
extern char D_005A5A40[];
struct func_0011E120_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_0011E120(struct func_0011E120_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005A56B0;
    arg0->unk2C = (s32)D_005A5A40;
    func_00202B70(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0xE4, 4);
    }
}
