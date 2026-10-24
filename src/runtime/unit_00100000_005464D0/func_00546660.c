#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B3638(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C1AF0[];
extern char D_005C1D80[];
struct func_00546660_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_00546660(struct func_00546660_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005C1AF0;
    arg0->unk2C = (s32)D_005C1D80;
    func_001B3638(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x7C, 4);
    }
}
