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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}
extern "C" void * func_001F0C00(void *);
extern "C" void * func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001F0BA8(void *, s32);

struct func_001F1BD8_v_s0 {
    char pad0[0xD0];
    s32 unkD0;
};

extern "C" void func_001F1BD8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    s32 v_s0;
    if (arg2 == 0) {
        p_s2 = buf1;
        func_001F0C00(p_s2);
        func_0029EA18(buf0, *(s32 *)((char *)(*p_s2) + 0xd0) != 0);
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
        func_001F0BA8(p_s2, 0x2);
    } else {
        if (arg2 == 1) {
            func_001F0C00(buf0);
            v_s0 = buf0[0];
            ((struct func_001F1BD8_v_s0 *)v_s0)->unkD0 = vcall_58((char *)(*(s32 *)(char *)arg3)) != 0;
            func_001F0BA8(buf0, 0x2);
        }
    }
}
