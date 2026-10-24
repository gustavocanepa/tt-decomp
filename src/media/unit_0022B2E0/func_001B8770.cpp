#include "types.h"

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32, s32);
};

extern "C" void func_001B7F40(void *arg0, int arg1);
extern "C" void func_001B7F98(void *arg0, void *arg1);
extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);
extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);

extern "C" void func_001B8770(void *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 small = n < 3;
    if (n == 2) {
        s32 *p1;
        s32 *p2;
        func_001B7F98(buf0, arg1);
        p1 = buf1;
        func_002027E0(p1, args);
        p2 = buf2;
        func_002027E0(p2, (char *)args + 4);
        {
            Obj *o = (Obj *)buf0[0];
            VEntry *e = (VEntry *)(o->vtbl + 0x370);
            e->fn((char *)o + e->delta, 0, p1[0], p2[0]);
        }
        func_00202788(p2, 2);
        func_00202788(p1, 2);
        func_001B7F40(buf0, 2);
    } else if (!small) {
        s32 *p3;
        s32 *p4;
        s32 *p5;
        func_001B7F98(buf0, arg1);
        p3 = buf3;
        func_001DF250(p3, args);
        p4 = buf4;
        func_002027E0(p4, (char *)args + 4);
        p5 = buf5;
        func_002027E0(p5, (char *)args + 8);
        {
            Obj *o = (Obj *)buf0[0];
            VEntry *e = (VEntry *)(o->vtbl + 0x370);
            e->fn((char *)o + e->delta, p3[0], p4[0], p5[0]);
        }
        func_00202788(p5, 2);
        func_00202788(p4, 2);
        func_001DF1F8(p3, 2);
        func_001B7F40(buf0, 2);
    }
}
