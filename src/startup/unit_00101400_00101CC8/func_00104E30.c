#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 GSBuffer__getBufferWidth();                                /* extern */
s32 func_00469230(s32, s32, s32, s32);      /* extern */

struct func_00104E30_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_00104E30(struct func_00104E30_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = arg0->unk4;
    func_00469230(temp_s0, GSBuffer__getBufferWidth(), arg0->unkC, 0);
}
