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

extern "C" s32 func_002BDA28(s32, s32);
extern "C" void func_002AC028(void *, void *);
extern "C" void func_002BA540(s32, void *);
extern "C" void func_0029BD98(void *, void *);
extern "C" void func_002AC170(void *, s32);

extern "C" void func_002BA678(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s1;
    p_s2 = buf1;
    v_s1 = func_002BDA28(0x1c, 0x4);
    func_002AC028(buf0, arg1);
    func_002BA540(v_s1, buf0);
    buf1[0] = v_s1;
    func_0029BD98(arg0, p_s2);
    func_002AC170(buf0, 0x2);
}
