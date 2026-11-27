#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_0027BEF0(void *);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_0029B4E0(void *, void *);
extern "C" void func_0027F148(s32, s32, void *, void *, void *);
extern "C" void func_0029B488(void *, s32);
extern "C" void func_00202788(void *, s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_0027BE98(void *, s32);

extern "C" void MSelectBox__insertSortChild(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 *p_s3;
    s32 *p_s2;
    s32 *p_s1;
    s32 *p_s0;
    if (arg2 >= 0x3) {
        func_0027BEF0(buf0);
        p_s3 = buf1;
        func_001DF250(p_s3, arg3);
        p_s2 = buf2;
        func_002027E0(p_s2, (char *)arg3 + 0x4);
        p_s1 = buf3;
        func_0029B4E0(p_s1, (char *)arg3 + 0x8);
        p_s0 = buf4;
        func_0029B4E0(p_s0, (char *)arg3 + 0xc);
        func_0027F148(buf0[0], *p_s3, p_s2, p_s1, p_s0);
        func_0029B488(p_s0, 0x2);
        func_0029B488(p_s1, 0x2);
        func_00202788(p_s2, 0x2);
        func_001DF1F8(p_s3, 0x2);
        func_0027BE98(buf0, 0x2);
    }
}
