#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0029BBB0(s32, s32);                    /* extern */
s32 func_002A7618();                            /* extern */

extern char D_005C4548[];
struct mColorObject__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mColorObject__structor_1(void *arg0, s32 arg1) {
    func_002A7618();
    ((struct mColorObject__structor_1_arg0 *)arg0)->unk4 = (s32)D_005C4548;
    func_0029BBB0(arg0 + 0x10, arg1);
}
