/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F7B74(s32, s32);                    /* extern */

void func_003F73A8(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 + 0xBC;
    func_004F7B74(arg0 + 0x9C, temp_s0);
    func_004F7B74(temp_s0, arg1);
}
