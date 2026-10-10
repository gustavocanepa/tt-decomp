/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FD730(s32, s32, s32);   /* extern */
s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */

extern s32 D_005A0DA4;
extern s32 D_005A0DC8;
void func_004DF1A0();
s32 func_004DF1F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s0;

    D_005A0DA4 = 1;
    temp_s0 = func_005038D8();
    func_004FD730(0x80000012, func_004DF1A0, 0);
    if (temp_s0 != 0) {
        func_00503928();
    }
    D_005A0DA4 = 0;
    D_005A0DC8 = 1;
    return 1;
}
