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

struct VEntry_50 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_50 { char pad0[4]; VEntry_50 *vtbl; };
static inline s32 vcall_50(char *o) {
    VEntry_50 *e = &((VObj_50 *)o)->vtbl[11];
    return e->fn(o + e->delta);
}
extern "C" void func_002969F0(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00296A20(void *, s32);

extern "C" void func_002A7A50(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    p_s0 = buf1;
    t1 = vcall_50((char *)(*(s32 *)(char *)arg1));
    buf1[0] = t1;
    func_002969F0(buf0, p_s0);
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
    func_00296A20(buf0, 0x2);
}
