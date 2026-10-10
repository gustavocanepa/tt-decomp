/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D06D0(void *, s32, s32, s32, s32, s32, s32); /* extern */

struct func_003D1058_arg0 {
    char pad0[0x12C8];
    s32 unk12C8;
    s32 unk12CC;
    s32 unk12D0;
};

void func_003D1058(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_003D06D0(arg0 + (arg1 * 0x320), ((struct func_003D1058_arg0 *)arg0)->unk12D0, ((struct func_003D1058_arg0 *)arg0)->unk12C8, ((struct func_003D1058_arg0 *)arg0)->unk12CC, arg2, arg3, arg4);
}
