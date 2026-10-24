#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00202B70(void *, s32);                     /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005B4C50[];
extern char D_005B4FC8[];
struct func_00535908_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
};

void func_00535908(struct func_00535908_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005B4C50;
    arg0->unk2C = (s32)D_005B4FC8;
    func_00202B70(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0xC0, 4);
    }
}
