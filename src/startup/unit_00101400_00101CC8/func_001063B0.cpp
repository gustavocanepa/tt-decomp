#include "types.h"
extern "C" void func_00105778(void *, s32, s32, s32);
extern "C" void func_00105860(void *, s32, s32);
extern "C" void func_001064F0(void *, s32, s32, s32, s32);

extern "C" void func_001063B0(void *o, s32 a1, s32 type, s32 w, s32 h) {
    if (w < 0) w = 0x280;
    if (h < 0) h = 0x1C0;
    if (type == 0x50) {
        func_001064F0(o, a1, w, 0x1C0, 0);
        func_00105778(o, 0, 0x50, 1);
        return func_00105860(o, w, 0x1C0);
    }
    if (type == 0x51) {
        func_001064F0(o, a1, w, 0x200, 1);
        func_00105778(o, 1, 0x51, 1);
        return func_00105860(o, w, 0x400);
    }
    func_001064F0(o, a1, w, h, 0);
    func_00105778(o, 1, type, 0);
    func_00105860(o, w, h);
}
