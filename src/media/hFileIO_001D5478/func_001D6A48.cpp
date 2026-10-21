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

struct VEntry_1c0 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_1c0 { char pad0[4]; VEntry_1c0 *vtbl; };
static inline s32 vcall_1c0(char *o) {
    VEntry_1c0 *e = &((VObj_1c0 *)o)->vtbl[108];
    return e->fn(o + e->delta);
}
extern "C" void func_001D35A0(void *);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001D3548(void *, s32);

extern "C" void func_001D6A48(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s2 = buf1;
    func_001D35A0(p_s2);
    func_0029EA18(buf0, vcall_1c0((char *)*p_s2));
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
    func_0029CEF0(buf0, 0x2);
    func_001D3548(p_s2, 0x2);
}
