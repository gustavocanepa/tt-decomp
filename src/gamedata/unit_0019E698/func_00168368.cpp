#include "types.h"

struct MPlayList_obj {
    char pad0[6];
    u8 shuffle;
};

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_00168090(void *arg0, s32 arg1);
extern "C" void * func_001680E8(void *arg0, void *arg1);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void * func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void func_00168368(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_001680E8(buf0, arg1);
        ((MPlayList_obj *)((s32 *)buf0[0])[4])->shuffle = v_s0 != 0;
        func_00168090(buf0, 2);
    } else {
        p_s2 = buf1;
        func_001680E8(p_s2, arg1);
        func_0029EA18(buf0, ((MPlayList_obj *)((s32 *)p_s2[0])[4])->shuffle != 0);
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
        func_00168090(p_s2, 0x2);
    }
}
