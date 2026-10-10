/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA460(s32, s32, s32);               /* extern */
s32 func_00503DB8();                                /* extern */
void func_00503ED0();                            /* extern */

extern s32 D_005A44B8;
void func_00503F48(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = func_00503DB8();
    func_00503ED0();
    func_004FA460(temp_s0, arg1, D_005A44B8 + 4);
}
