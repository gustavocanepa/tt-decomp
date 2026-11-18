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

struct VEntry_60 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline s32 vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[12];
    return e->fn(o + e->delta);
}
extern "C" void func_002ADC48(void *, void *);
extern "C" void func_00123F58(void *, void *);
extern "C" void func_00126FB0(s32, s32);
extern "C" void func_00123F00(void *, s32);
extern "C" void func_002ADBF0(void *, s32);

extern "C" void func_00125148(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 t1;
    func_002ADC48(buf0, arg3);
    t1 = vcall_60((char *)(*(s32 *)(char *)buf0));
    p_s0 = buf1;
    func_00123F58(p_s0, arg1);
    func_00126FB0(*p_s0, t1);
    func_00123F00(p_s0, 0x2);
    func_002ADBF0(buf0, 0x2);
}
