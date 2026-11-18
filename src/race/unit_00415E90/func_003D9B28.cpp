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

extern "C" s32 func_003D9710(void);
extern "C" s32 func_003D8FF0(s32, void *);
extern "C" void func_003D9A80(void *, void *);
extern "C" void func_003D9A90(void *, void *);

extern "C" s32 func_003D9B28(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s2;
    s32 *p_s0;
    v_s2 = func_003D8FF0(func_003D8FF0(func_003D8FF0(func_003D9710(), buf0), (char *)buf0 + 0x4), (char *)buf0 + 0x8);
    func_003D9A80(arg0, buf0);
    p_s0 = buf1;
    v_s2 = func_003D8FF0(func_003D8FF0(func_003D8FF0(v_s2, p_s0), (char *)buf1 + 0x4), (char *)buf1 + 0x8);
    func_003D9A90(arg0, p_s0);
    return v_s2;
}
