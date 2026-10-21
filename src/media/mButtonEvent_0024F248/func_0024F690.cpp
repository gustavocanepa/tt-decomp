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
extern "C" void func_0024EE50(void *, void *, s32);
extern "C" void func_0024F450(void *, void *);
extern "C" void func_0024F3F8(void *, s32);

struct func_0024F690_v_s0 {
    char pad0[0x34];
    s32 unk34;
};
struct func_0024F690_arg3 {
    char pad0[0x18];
    s32 unk18;
};

extern "C" void func_0024F690(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    if (arg2 == 0x7) {
        func_0024EE50(arg0, arg1, 0x6);
        func_0024F450(buf0, arg1);
        v_s0 = buf0[0];
        ((struct func_0024F690_v_s0 *)v_s0)->unk34 = vcall_58((char *)(((struct func_0024F690_arg3 *)arg3)->unk18)) != 0;
        func_0024F3F8(buf0, 0x2);
    }
}
