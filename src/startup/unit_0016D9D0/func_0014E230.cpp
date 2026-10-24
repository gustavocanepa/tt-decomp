#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" s32 func_0014D580(void *arg0, void *arg1);
extern "C" void func_0014D528(void *arg0, s32 arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" s32 func_001324D8(s32 arg0);
extern "C" void func_003FB970(void *o, s32 a, s32 b);
extern "C" void func_00128418(void *arg0, s32 arg1);

extern "C" void func_0014E230(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    char *s2;
    s32 v_s0;

    func_0014D580(buf0, arg1);
    s2 = *(char **)((char *)buf0[0] + 0x10);
    func_0014D528(buf0, 2);
    if (arg2 >= 0x2) {
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_00128470(buf0, (char *)arg3 + 4);
        func_003FB970(s2, v_s0, func_001324D8(buf0[0]));
        func_00128418(buf0, 0x2);
    }
}
