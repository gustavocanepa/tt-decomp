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

extern char D_0057C650[];
extern "C" void func_00292AF8(void *);
extern "C" void func_00291F58(void *, s32, void *);
extern "C" void func_002A4160(void *, void *, void *);
extern "C" void func_002A2770(void *, s32);
extern "C" void func_00290478(void *, s32);

extern "C" void func_002A40E0(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    func_00292AF8(buf0);
    p_s0 = buf1;
    func_00291F58(p_s0, buf0[0], arg1);
    func_002A4160(arg0, p_s0, &D_0057C650);
    func_002A2770(p_s0, 0x2);
    func_00290478(buf0, 0x2);
}
