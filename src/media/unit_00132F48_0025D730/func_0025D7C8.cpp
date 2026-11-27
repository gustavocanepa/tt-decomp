#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_0025D470(void *arg0, void *arg1);
extern "C" void func_0025D418(void *arg0, s32 arg1);

extern "C" void func_0025D7C8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    if (arg2 > 0) {
        func_0025D470(buf0, arg1);
        v_s0 = buf0[0];
        *(s32 *)((char *)v_s0 + 0x64) = vcall_58((char *)(*(s32 *)(char *)arg3)) != 0;
        func_0025D418(buf0, 0x2);
    }
}
