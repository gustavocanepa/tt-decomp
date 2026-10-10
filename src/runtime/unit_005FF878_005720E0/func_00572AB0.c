/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(void *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */

struct func_00572AB0_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
};

void func_00572AB0(struct func_00572AB0_arg0 *arg0, s32 arg1) {
    func_004F4348(arg0->unk0);
    arg0->unk40 = arg1;
    func_004F45D8(arg0, 5, 0, 0, 0);
}
