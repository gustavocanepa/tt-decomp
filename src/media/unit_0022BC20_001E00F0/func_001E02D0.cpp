#include "types.h"

extern "C" void func_001DF250(s32 *arg0);
extern "C" s32 func_001E2EA0(s32 arg0);
extern "C" void func_001E63F8(s32 *arg0, s32 *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_001E6428(s32 *arg0, s32 arg1);
extern "C" void func_001DF1F8(s32 *arg0, s32 arg1);

extern "C" void func_001E02D0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 temp;
    s32 *ptemp = &temp;
    s32 newVal;
    s32 oldVal;

    func_001DF250(p1);
    temp = func_001E2EA0(*p1);
    func_001E63F8(buf0, ptemp);
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
    func_001E6428(buf0, 2);
    func_001DF1F8(p1, 2);
}
