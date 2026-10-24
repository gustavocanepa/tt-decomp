#include "types.h"

extern "C" void func_002ADC48(s32 *arg0, s32 arg1);
extern "C" s32 func_002AFE68(s32 arg0);
extern "C" void func_00249D88(s32 arg0, s32 arg1);
extern "C" void func_00247A80(s32 *arg0, s32 arg1);

extern "C" void func_00247AD8(s32 *arg0, s32 arg1);
extern "C" void func_002ADBF0(s32 *arg0, s32 arg1);

extern "C" void func_002481B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];

    if (arg2 > 0) {
        func_00247AD8(buf0, arg1);
        s32 *p1 = buf1;
        func_002ADC48(p1, arg3);
        s32 base0 = buf0[0];
        s32 result = func_002AFE68(p1[0]);
        func_00249D88(base0, result);
        func_002ADBF0(p1, 2);
        func_00247A80(buf0, 2);
    }
}
