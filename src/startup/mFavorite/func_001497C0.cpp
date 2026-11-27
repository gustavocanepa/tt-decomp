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

extern "C" void func_00141FF0(void *);
extern "C" void func_00141F98(void *, s32);
extern "C" void func_001695F8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00169368(void *, s32);

extern "C" void func_001497C0(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_00141FF0(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10) + 0x1EA0;
    func_00141F98(buf0, 0x2);
    func_001695F8(buf0, v_s0);
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
    func_00169368(buf0, 0x2);
}
