#include "types.h"

extern "C" void func_002027E0(s32 *arg0);
extern "C" s32 func_0020E470(s32 arg0);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);
extern "C" void func_00202788(s32 *arg0, s32 arg1);

extern "C" void func_00204D30(s32 *arg0, s32 arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1;
    s32 newVal;
    s32 oldVal;

    if (arg2 == 0) {
        p1 = buf1;
        func_002027E0(p1);
        func_0029EA18(buf0, func_0020E470(*p1) != 0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(buf0, 2);
        func_00202788(p1, 2);
    }
}
