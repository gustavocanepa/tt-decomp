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
extern "C" void func_001FCB58(void *);
extern "C" void func_001E6480(void *, void *);
extern "C" void func_00200068(s32, s32, s32);
extern "C" void func_001E6428(void *, s32);
extern "C" void func_001FCB00(void *, s32);

extern "C" void func_001FD350(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 == 0x2) {
        func_001FCB58(buf0);
        p_s0 = buf1;
        func_001E6480(p_s0, (char *)arg3 + 0x4);
        v_s1 = buf0[0];
        func_00200068(v_s1, vcall_58((char *)(*(s32 *)(char *)arg3)), *p_s0);
        func_001E6428(p_s0, 0x2);
        func_001FCB00(buf0, 0x2);
    }
}
