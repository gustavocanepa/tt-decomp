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

extern "C" void func_0029CF48(void *, void *);
extern "C" void func_00123F58(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_00127040(s32, s32);
extern "C" void func_00123F00(void *, s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void MCarFace__set_debug_display(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 > 0) {
        func_0029CF48(buf0, arg3);
        p_s0 = buf1;
        func_00123F58(p_s0, arg1);
        v_s1 = *p_s0;
        func_00127040(v_s1, func_0029E9F0(buf0[0]) != 0);
        func_00123F00(p_s0, 0x2);
        func_0029CEF0(buf0, 0x2);
    }
}
