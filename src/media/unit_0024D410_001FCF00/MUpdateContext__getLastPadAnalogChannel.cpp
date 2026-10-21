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
extern "C" f32 func_001FF2B0(s32, s32, s32);
extern "C" void func_0029B380(void *, f32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_001FCB00(void *, s32);

struct MUpdateContext__getLastPadAnalogChannel_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void MUpdateContext__getLastPadAnalogChannel(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 v_s0;
    s32 *p_s1;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0x2) {
        func_001FCB58(buf0);
        v_s1 = buf0[0];
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        t1 = func_001FF2B0(v_s1, v_s0, vcall_58((char *)(((struct MUpdateContext__getLastPadAnalogChannel_arg3 *)arg3)->unk4)));
        p_s1 = buf1;
        func_0029B380(p_s1, t1);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_00299AB0(p_s1, 0x2);
        func_001FCB00(buf0, 0x2);
    }
}
