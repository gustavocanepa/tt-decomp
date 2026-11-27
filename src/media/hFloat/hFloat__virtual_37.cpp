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

extern "C" void func_0029B380(void *, f32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);

struct func_0029A6E0_arg0 {
    char pad0[0x10];
    f32 unk10;
};

extern "C" void hFloat__virtual_37(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_0029B380(buf0, ((struct func_0029A6E0_arg0 *)arg0)->unk10);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_00299AB0(buf0, 0x2);
}
