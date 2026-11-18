#include "types.h"

extern f32 D_00585D04;
extern "C" void func_00472268(s32, s32);

extern "C" void func_002D69D0(void *self, s32 on) {
    s32 i = -10;
    f32 v;
    if (on) i = 0;
    v = (f32)i;
    D_00585D04 = v;
    func_00472268(10, (s32)(v * 0x1.000000p+8f));
}
