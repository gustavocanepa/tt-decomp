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

struct func_0012F138_S {
    char pad0[0x4D8];
    s32 unk490;
};

extern "C" void func_00128470(void *, void *);
extern "C" void *func_001324D8(s32);
extern "C" void func_004057A8(void *, s32);
extern "C" void func_00128418(void *, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void func_0012F138(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        t1 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_00128470(buf0, arg1);
        func_004057A8(func_001324D8(buf0[0]), t1);
        func_00128418(buf0, 2);
    } else {
        p_s2 = buf1;
        func_00128470(p_s2, arg1);
        func_0029EA18(buf0, ((struct func_0012F138_S *)func_001324D8(*p_s2))->unk490);
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
        func_00128418(p_s2, 0x2);
    }
}
