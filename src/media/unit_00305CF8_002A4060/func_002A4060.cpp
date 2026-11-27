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

extern "C" void func_00292AF8(void *);
extern "C" void func_002A2740(void *, void *);
extern "C" s32 func_00291638(s32, void *, void *);
extern "C" void func_002A2770(void *, s32);
extern "C" void func_00290478(void *, s32);

extern "C" s32 func_002A4060(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s0;
    s32 v_s1;
    func_00292AF8(buf0);
    p_s0 = buf1;
    buf2[0] = (s32)arg0;
    func_002A2740(p_s0, buf2);
    v_s1 = func_00291638(buf0[0], arg1, p_s0);
    func_002A2770(p_s0, 0x2);
    func_00290478(buf0, 0x2);
    return v_s1;
}
