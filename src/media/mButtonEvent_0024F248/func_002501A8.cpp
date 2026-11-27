#include "types.h"

extern "C" void func_0024FE68(s32 *arg0);
extern "C" void func_00247AD8(s32 *arg0, s32 arg1);
extern "C" void func_00250208(s32 arg0, s32 *arg1);
extern "C" void func_00247A80(s32 *arg0, s32 arg1);
extern "C" void func_0024FE10(s32 *arg0, s32 arg1);

extern "C" void func_002501A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0024FE68(buf0);
        func_00247AD8(buf1, arg3);
        func_00250208(buf0[0], buf1);
        func_00247A80(buf1, 2);
        func_0024FE10(buf0, 2);
    }
}
