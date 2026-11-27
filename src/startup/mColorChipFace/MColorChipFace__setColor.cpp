#include "types.h"

extern "C" void func_00293220(s32 *arg0, s32 arg1);
extern "C" void func_0013CB08(s32 *arg0, s32 arg1);
extern "C" void func_0013D428(s32 arg0, s32 *arg1);
extern "C" void func_002931C8(s32 *arg0, s32 arg1);
extern "C" void func_0013CAB0(s32 *arg0, s32 arg1);

extern "C" void MColorChipFace__setColor(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[8];
    s32 buf1[4];

    if (arg2 > 0) {
        func_0013CB08(buf0, arg1);
        s32 val0 = buf0[0];
        s32 *p1 = buf1;
        func_00293220(p1, arg3);
        func_0013D428(val0, p1);
        func_002931C8(p1, 2);
        func_0013CAB0(buf0, 2);
    }
}
