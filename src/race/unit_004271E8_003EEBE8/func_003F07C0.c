#include "types.h"
s32 func_003F1860(void);
s32 func_003F0608(void *, s16, s16, s16, s32, f32, s32, s32, void *, void *, f32);
s32 func_003F07C0(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    char *temp_v0;
    s32 sp[2];
    if (func_003F1860() != 1) return 0;
    temp_v0 = (char *)(arg1 * 0x10) + *(s32 *)(*(char **)(arg0 + 4) + 0x1C);
    return func_003F0608(arg0, *(s16 *)(temp_v0 + 4), *(s16 *)(temp_v0 + 6), *(s16 *)(temp_v0 + 8), arg2, fparg0, 1, arg3, &sp[0], &sp[1], fparg1);
}
