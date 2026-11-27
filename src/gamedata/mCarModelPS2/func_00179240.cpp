#include "types.h"
extern "C" float func_0030C6B0(void *, s32);
extern "C" float func_0030C648(void *, s32);
extern "C" float func_0030C718(void *, s32);
extern "C" void func_0041AA80(void *, s32, float, float, float);
extern "C" void func_00179240(void *self, s32 arg1) {
    s32 start = arg1 == 0 ? 2 : 0;
    for (s32 i = 0; i < 2; ++i) {
        s32 idx = i + start;
        float a = func_0030C6B0((char *)self + 0x8D0, idx);
        float b = func_0030C648((char *)self + 0x8D0, idx);
        float c = func_0030C718((char *)self + 0x8D0, idx);
        func_0041AA80((char *)self + 0x2DC, idx, a, b, c);
    }
}
