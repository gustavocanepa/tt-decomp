#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 func_00294F40();                                /* extern */
s32 func_005261B0(s32, u32, u32);           /* extern */

extern char D_005F0C50[];
struct func_00295028_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00295028(struct func_00295028_arg0 *arg0, u32 arg1) {
    u32 temp_v0;

    temp_v0 = func_00294F40();
    if (arg1 >= temp_v0) {
        func_005261B0((s32)D_005F0C50, arg1, temp_v0);
    }
    return arg0->unk14 + (arg1 * 4);
}
