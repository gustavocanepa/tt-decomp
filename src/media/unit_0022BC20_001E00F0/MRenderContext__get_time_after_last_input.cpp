#include "types.h"
extern "C" void func_001DF1F8(void *, s32) throw();
extern "C" s32 func_001DF250(void *, s32) throw();
extern "C" float func_001FFD78(s32);
extern "C" void func_001FFDC0(s32, float);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_00299B08(void *, s32);
extern "C" float func_0029B188(s32);
extern "C" void func_0029B380(void *, float);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void MRenderContext__get_time_after_last_input(s32 *arg0, s32 arg1, s32 sel, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    if (sel == 0) {
        func_001DF250(buf0, arg1);
        float f = func_001FFD78(*(s32 *)(buf0[0] + 0x10));
        s32 *p1 = buf1;
        func_0029B380(p1, f);
        if (arg0 != p1) {
            s32 newVal = *p1;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_00299AB0(p1, 2);
        func_001DF1F8(buf0, 2);
    } else if (sel > 0) {
        func_00299B08(buf0, arg3);
        s32 *p2 = buf2;
        func_001DF250(p2, arg1);
        s32 h = *(s32 *)(p2[0] + 0x10);
        func_001FFDC0(h, func_0029B188(buf0[0]));
        func_001DF1F8(p2, 2);
        func_00299AB0(buf0, 2);
    }
}
