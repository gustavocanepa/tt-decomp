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
extern "C" void func_0029CF48(void *);
extern "C" void func_0029E9F8(s32, s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void func_0029E1B0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    func_0029CF48(buf0);
    v_s1 = buf0[0];
    func_0029E9F8(v_s1, vcall_58((char *)(*(s32 *)(char *)arg3)));
    func_0029CEF0(buf0, 0x2);
}
