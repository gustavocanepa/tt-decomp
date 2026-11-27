#include "types.h"

extern "C" void func_001D0060(s32 *arg0, s32 arg1);
extern "C" s32 func_001D1D50(s32 arg0);
extern "C" void func_001D1D58(s32 arg0, s32 arg1);
extern "C" void func_001D0008(s32 *arg0, s32 arg1);

extern "C" void func_001D09F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];

    if (arg2 > 0) {
        func_001D0060(buf0, arg1);
        s32 *p1 = buf1;
        func_001D0060(p1, arg3);
        s32 base0 = buf0[0];
        s32 result = func_001D1D50(p1[0]);
        func_001D1D58(base0, result);
        func_001D0008(p1, 2);
        func_001D0008(buf0, 2);
    }
}
