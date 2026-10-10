#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0020D5E8(s32, s32);                /* extern */
s32 func_0020D6C8(s32, s32);                /* extern */

struct func_001E5440_arg0 {
    char pad0[0x1CF8];
    s32 unk1CF8;
};

s32 func_001E5440(struct func_001E5440_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk1CF8;
    if (temp_v0 != 0) {
        func_0020D5E8(temp_v0, 0);
    }
    arg0->unk1CF8 = arg1;
    if (arg1 != 0) {
        func_0020D6C8(arg1, 0);
        func_0020D5E8(arg0->unk1CF8, 1);
    }
}
