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
extern "C" void func_002C0B68(void *, void *, s32);
extern "C" void func_002B01F8(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002ADBF0(void *, s32);
extern "C" void func_002BDA70(void *, s32, s32);

extern "C" void func_002C0D60(s32 *arg0, void *arg1, s32 arg2, char **arg3, s32 *arg4) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s2 = buf1;
    func_002C0B68(p_s2, arg0, vcall_58((char *)(*(s32 *)(char *)arg4)));
    func_002B01F8(buf0, p_s2);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_002ADBF0(buf0, 0x2);
    {
        Rep *q = (Rep *)(*p_s2 - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_002BDA70(q, cap, 4);
        }
    }
}
