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
extern "C" s32 func_004C9A38(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void func_0023C3F8(s32 *arg0, void *arg1, s32 arg2, char **arg3, s32 *arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if ((s32)arg3 > 0) {
        func_0029EA18(buf0, func_004C9A38((char *)arg0 + 0x10, vcall_58((char *)(*(s32 *)(char *)arg4))));
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
        func_0029CEF0(buf0, 0x2);
    }
}
