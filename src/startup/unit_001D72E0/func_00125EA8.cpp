#include "types.h"

extern "C" void func_00123F58(s32 *arg0);
extern "C" s32 func_00127038(s32 arg0);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);
extern "C" void func_00123F00(s32 *arg0, s32 arg1);

extern "C" void func_00125EA8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_00123F58(p1);
    func_0029EA18(buf0, func_00127038(*p1) != 0);
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
    func_00123F00(p1, 2);
}
