#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B0928(void *, s32, s32);                    /* extern */
s32 func_004B1720(void *);                      /* extern */

struct func_00572020_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad20[0xC];
    s32 unk2C;
};

void func_00572020(struct func_00572020_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk2C = arg4;
    func_004B0928(arg0, arg2, arg3);
    arg0->unk14 = arg1;
    arg0->unk18 = arg1;
    arg0->unk1C = (s32) (arg1 - 1);
    func_004B1720(arg0);
}
