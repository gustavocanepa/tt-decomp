#include "types.h"

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_0029EA78(void *arg0);
extern "C" s32 func_0029CF90(void *arg0, void *arg1);
extern "C" void func_0029B380(void *arg0, f32 fparg0);
extern "C" void func_00299AB0(void *arg0, s32 arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void func_0029A940(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    func_0029EA78(buf0);
    if (func_0029CF90(buf0, arg3) != 0) {
        t1 = (f32)vcall_58((char *)buf0[0]);
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
    }
    if (arg0 != arg3) {
        newVal = *arg3;
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
}
