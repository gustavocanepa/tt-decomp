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

extern "C" void func_0023CC50(void *);
extern "C" void func_0023C5F8(void *);
extern "C" s32 func_004C9C50(s32);
extern "C" void func_004C9C08(s32, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0023C4C8(void *, s32);
extern "C" void func_0023CBF8(void *, s32);

extern "C" void func_0023C918(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_0023CC50(buf0);
    p_s2 = buf1;
    func_0023C5F8(p_s2);
    v_s0 = *p_s2;
    func_004C9C08(v_s0 + 0x10, func_004C9C50(buf0[0] + 0x14));
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0023C4C8(p_s2, 0x2);
    func_0023CBF8(buf0, 0x2);
}
