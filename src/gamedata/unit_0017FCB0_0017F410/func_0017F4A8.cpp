#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_0017C4A0(void *arg0, void *arg1);
extern "C" void func_0017C448(void *arg0, s32 arg1);

extern "C" void func_0017F4A8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    func_0017C4A0(buf0, arg1);
    v_s1 = buf0[0];
    *(s32 *)((char *)v_s1 + 0x114) = vcall_58((char *)(*(s32 *)(char *)arg3)) != 0;
    func_0017C448(buf0, 2);
}
