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

struct VEntry_40 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_40 { char pad0[4]; VEntry_40 *vtbl; };
static inline s32 vcall_40(char *o) {
    VEntry_40 *e = &((VObj_40 *)o)->vtbl[8];
    return e->fn(o + e->delta);
}
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void adhoc__get_weak_count(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_0029EA18(buf0, vcall_40((char *)*(s32 *)arg1));
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
}
