/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002F04D8(s32, s32);                        /* extern */
s32 func_0036C908(void *, s32, s32, s32);       /* extern */

struct func_003052F0_temp_v0 {
    char pad0[0x64E];
    u8 unk64E;
};

struct func_003052F0_arg0 {
    char pad0[0x84];
    void *unk84;
    char pad88[0x54];
    s32 unkDC;
};

void func_003052F0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_003052F0_temp_v0 *temp_v0;

    temp_v0 = func_002F04D8(M2C_FIELD(((struct func_003052F0_arg0 *)arg0)->unk84, s32 *, 0x70), arg2) + 0x104;
    if ((((struct func_003052F0_arg0 *)arg0)->unkDC == 0) && (temp_v0->unk64E == 0)) {
        func_0036C908(arg0 + 0xF4, arg1, arg2, arg3);
    }
}
