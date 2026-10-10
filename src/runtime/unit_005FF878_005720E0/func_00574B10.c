/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(void *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */

struct func_00574B10_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_00574B10(struct func_00574B10_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004F4348(arg0->unk0);
    arg0->unk40 = arg1;
    arg0->unk44 = arg2;
    arg0->unk48 = arg3;
    func_004F45D8(arg0, 5, 1, 0, 0);
}
