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
extern "C" void func_00128470(void *);
extern "C" s32 func_001324D8(s32);
extern "C" void func_00406A10(s32, s32, s32);
extern "C" void func_00128418(void *, s32);

struct func_0012E9F0_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void func_0012E9F0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 v_s0;
    if (arg2 >= 0x2) {
        func_00128470(buf0);
        v_s1 = vcall_58((char *)(*(s32 *)(char *)arg3));
        v_s0 = vcall_58((char *)(((struct func_0012E9F0_arg3 *)arg3)->unk4));
        func_00406A10(func_001324D8(buf0[0]), v_s1, v_s0);
        func_00128418(buf0, 0x2);
    }
}
