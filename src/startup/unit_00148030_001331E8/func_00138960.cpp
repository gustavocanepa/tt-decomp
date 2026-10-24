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

extern "C" void func_00128470(void *);
extern "C" s32 func_001324D8(s32);
extern "C" void func_00128418(void *, s32);
extern "C" f32 func_002E4958(s32);
extern "C" void func_0029B380(void *, f32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);

extern "C" void func_00138960(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_00128470(buf0);
    v_s0 = func_001324D8(buf0[0]) + 0x4e8;
    func_00128418(buf0, 0x2);
    func_0029B380(buf0, func_002E4958(v_s0));
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
    func_00299AB0(buf0, 0x2);
}
