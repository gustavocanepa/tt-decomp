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

struct VEntry_190 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_190 { char pad0[4]; VEntry_190 *vtbl; };
static inline s32 vcall_190(char *o) {
    VEntry_190 *e = &((VObj_190 *)o)->vtbl[56];
    return e->fn(o + e->delta);
}
extern "C" void func_001D35A0(void *);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001D3548(void *, s32);

extern "C" void func_001D3B48(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_001D35A0(buf0);
    t1 = vcall_190((char *)buf0[0]);
    p_s2 = buf1;
    func_0029EA18(p_s2, t1);
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
    func_0029CEF0(p_s2, 0x2);
    func_001D3548(buf0, 0x2);
}
