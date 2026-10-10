#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043DEE8(s32 *, s32, s32);                 /* extern */
s32 func_004412F0(s32, s32, s32, s32, s32, s32, void *); /* extern */
s32 *func_00447FB0(s32, s32);                       /* extern */
s32 func_0044C478(s32, s32, s32, s32, s32);     /* extern */

struct func_0044B708_arg7 {
    char pad0[0x164];
    s32 unk164;
};

s32 func_0044B708(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, struct func_0044B708_arg7 *arg7) {
    s32 *temp_v0;

    temp_v0 = func_00447FB0(arg1 + 4, arg2);
    if ((temp_v0 != NULL) && ((*temp_v0 ^ 0xD) == 0)) {
        func_004412F0(arg0, func_0043DEE8(temp_v0, arg1, arg2), arg3, arg4, arg5, arg6, arg7);
    } else {
        func_0044C478(arg0, arg1, arg2, arg7->unk164, arg5);
    }
    return arg0;
}
