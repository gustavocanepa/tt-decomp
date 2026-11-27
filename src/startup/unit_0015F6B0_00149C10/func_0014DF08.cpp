#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_0014D528(void *arg0, int arg1);
extern "C" void func_0014D580(void *arg0, void *arg1);
extern "C" void func_003FBEB0(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_0014DF08(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s3;
    s32 v_s2;
    s32 v_flag;
    if (arg2 > 0) {
        func_0014D580(buf0, arg1);
        v_s3 = ((s32 *)buf0[0])[4];
        func_0014D528(buf0, 2);
        v_s2 = vcall_58((char *)(*(s32 *)(char *)arg3));
        v_flag = 0;
        if (!((arg2 < 0x2))) {
            v_flag = vcall_58((char *)(*(s32 *)((char *)arg3 + 4))) != 0;
        }
        func_003FBEB0((void *)v_s3, v_s2, v_flag);
    }
}
