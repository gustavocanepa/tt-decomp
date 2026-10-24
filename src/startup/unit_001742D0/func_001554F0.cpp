#include "types.h"

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

static inline s32 vcall_B0(char *o) {
    VEntry *e = (VEntry *)(*(char **)(o + 0x4C) + 0x110);
    return e->fn(o + e->delta);
}

extern "C" void func_00151AE8(void *arg0, void *arg1);
extern "C" void func_00151A90(void *arg0, int arg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);
extern "C" int GT4MC__FileGT4GameData__loadInstance(void *arg0, void *arg1, int arg2, void *arg3, void *arg4, void *arg5);
extern char D_00520CA0[];
extern char D_005206C0[];

extern "C" void func_001554F0(void **arg0, void *arg1) {
    s32 buf0[4];
    s32 var;
    void *obj;
    s32 r;

    func_00151AE8(buf0, arg1);
    obj = *(void **)((char *)buf0[0] + 0x10);
    var = 0;
    if (obj != 0) {
        char *desc = *(char **)((char *)obj + 0x4C);
        var = GT4MC__FileGT4GameData__loadInstance(*(void **)(desc + 4), D_00520CA0, 0,
                            (char *)obj + *(s16 *)desc, D_005206C0, obj);
    }
    func_00151A90(buf0, 2);
    if (var != 0) {
        r = vcall_B0((char *)var);
    } else {
        r = 0;
    }
    func_0029EA18(buf0, (void *)r);
    if ((void *)arg0 != (void *)buf0) {
        void *newVal = (void *)buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        void *oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(buf0, 2);
}
