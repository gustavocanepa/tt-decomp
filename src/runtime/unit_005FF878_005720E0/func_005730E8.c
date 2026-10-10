/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(void *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */
s32 func_004F7B74(void *, s32);                 /* extern */

struct func_005730E8_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s8 unk4C;
};

void func_005730E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_004F4348(((struct func_005730E8_arg0 *)arg0)->unk0);
    ((struct func_005730E8_arg0 *)arg0)->unk40 = arg1;
    ((struct func_005730E8_arg0 *)arg0)->unk44 = arg2;
    ((struct func_005730E8_arg0 *)arg0)->unk48 = arg3;
    ((struct func_005730E8_arg0 *)arg0)->unk4C = 0;
    if (arg4 != 0) {
        func_004F7B74(arg0 + 0x4C, arg4);
    }
    func_004F45D8(arg0, 1, 0, 0, 0);
}
