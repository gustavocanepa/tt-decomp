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

extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002A7578(void *, s32 *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void func_001235C0(s32 *arg0, s32 arg1, char **arg2) {
    s32 buf0[4];
    s32 sp10;
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        s32 t = vcall_58((char *)(*(s32 *)(char *)arg2));
        func_0029EA18(buf0, (t - 5) % 7);
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
        func_0029CEF0(buf0, 0x2);
        return;
    }
    sp10 = 0;
    func_002A7578(buf0, &sp10);
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
    func_002A75A8(buf0, 0x2);
}
