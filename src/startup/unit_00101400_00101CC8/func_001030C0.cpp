#include "types.h"

extern "C" void func_0047DB20(void *, s32, s32);
extern "C" void func_00466B28(s32);

extern "C" s32 func_001030C0(s32 arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v;
    func_0047DB20(buf0, arg0, 1);
    v = buf1[0];
    func_00466B28(v);
    return v;
}
