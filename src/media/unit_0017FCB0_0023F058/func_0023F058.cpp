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

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[14];
    return e->fn(o + e->delta);
}
extern "C" void * func_0023E810(void *);
extern "C" void func_0023E7B8(void *, s32);
extern "C" void * func_0029B380(void *, f32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);

struct func_0023F058_v_s0 {
    char pad0[0x180];
    f32 unk180;
};

extern "C" void func_0023F058(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    f32 t1;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_0023E810(buf0);
        v_s0 = buf0[0];
        t1 = vcall_60((char *)*(s32 *)arg3);
        ((struct func_0023F058_v_s0 *)v_s0)->unk180 = t1;
        func_0023E7B8(buf0, 0x2);
    } else {
        p_s1 = buf1;
        func_0023E810(p_s1);
        func_0029B380(buf0, *(f32 *)((char *)*p_s1 + 0x180));
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
        func_00299AB0(buf0, 0x2);
        func_0023E7B8(p_s1, 0x2);
    }
}
