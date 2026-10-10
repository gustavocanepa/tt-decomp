/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(void *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */

struct func_00572C78_arg0 {
    s32 unk0;
    char pad4[0x7C];
    s32 unk80;
    s32 unk84;
};

void func_00572C78(struct func_00572C78_arg0 *arg0, s32 arg1, s32 arg2) {
    func_004F4348(arg0->unk0);
    arg0->unk80 = arg1;
    arg0->unk84 = arg2;
    func_004F45D8(arg0, 2, 1, 0, 0);
}
