#include "types.h"

extern "C" void func_0029B458(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029B488(void *, s32);
extern "C" void func_0020B408(s32 *, s32);

extern "C" void func_0021BC28(s32 *arg0, s32 arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    p_s1 = (s32 *)((char *)arg0 + 0xD4);
    buf1[0] = 0;
    func_0029B458(buf0, buf1);
    if ((char *)p_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *p_s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *p_s1 = newVal;
    }
    func_0029B488(buf0, 2);
    func_0020B408(arg0, arg1);
}
