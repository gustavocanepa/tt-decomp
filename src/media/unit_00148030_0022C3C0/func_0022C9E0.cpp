#include "types.h"

extern "C" void func_0022C140(s32 *arg0);
extern "C" void func_0022CF58(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_002931C8(s32 *arg0, s32 arg1);
extern "C" void func_0022C0E8(s32 *arg0, s32 arg1);

extern "C" void func_0022C9E0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_0022C140(p1);
    func_0022CF58(buf0, *p1);
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
    func_002931C8(buf0, 2);
    func_0022C0E8(p1, 2);
}
