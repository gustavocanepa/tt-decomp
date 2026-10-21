#include "types.h"

extern "C" void func_00251678(void *, void *);
extern "C" void func_001DF250(void *, s32 *);
extern "C" void func_00202758(void *, s32 *);
extern "C" void func_002570F0(s32, s32, s32);
extern "C" void func_00202788(void *, s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_00251620(void *, s32);

extern "C" void MListBox__setItemTemplate(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s1;
    s32 *p_s0;
    s32 *p_v0;
    if (arg2 == 0x2) {
        func_00251678(buf0, arg1);
        p_s1 = buf1;
        func_001DF250(p_s1, arg3);
        p_v0 = buf3;
        p_s0 = buf2;
        *p_v0 = arg3[1];
        func_00202758(p_s0, p_v0);
        func_002570F0(buf0[0], *p_s1, *p_s0);
        func_00202788(p_s0, 0x2);
        func_001DF1F8(p_s1, 0x2);
        func_00251620(buf0, 0x2);
    }
}
