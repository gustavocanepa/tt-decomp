#include "types.h"

extern "C" void func_002ADC48(s32 *arg0);
extern "C" void func_002B04F8(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_002ADBF0(s32 *arg0, s32 arg1);
extern "C" void func_002ADBF0(s32 *arg0, s32 arg1);

extern "C" void func_002AEF28(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_002ADC48(p1);
    func_002B04F8(buf0, *p1);
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
    func_002ADBF0(buf0, 2);
    func_002ADBF0(p1, 2);
}
