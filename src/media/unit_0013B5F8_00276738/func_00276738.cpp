#include "types.h"

extern "C" void func_00276388(s32 *arg0, s32 arg1);
extern "C" void func_002027E0(s32 *arg0, s32 arg1);
extern "C" void func_00276CC8(s32 arg0, s32 arg1);
extern "C" void func_00276330(s32 *arg0, s32 arg1);
extern "C" void func_00202788(s32 *arg0, s32 arg1);

extern "C" void func_00276738(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[8];
    s32 buf1[4];

    if (arg2 > 0) {
        func_00276388(buf0, arg1);
        s32 val0 = buf0[0];
        s32 *p1 = buf1;
        func_002027E0(p1, arg3);
        func_00276CC8(val0, p1[0]);
        func_00202788(p1, 2);
        func_00276330(buf0, 2);
    }
}
