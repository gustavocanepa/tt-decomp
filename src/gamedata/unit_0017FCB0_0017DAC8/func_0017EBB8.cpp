#include "types.h"

struct Obj00370D70;

struct VEnt00195270 {
    s16 delta;
    s16 pad;
    void *(*fn)(void *);
};

struct ObjA00195270 {
    char pad0[0x64];
    VEnt00195270 *vtbl;
};

extern "C" int func_0017C870(s32);
extern "C" void func_00319740(void *p, s32 v);
extern "C" f32 func_00319700(Obj00370D70 *p);

extern "C" f32 func_0017EBB8(s32 arg0, s32 arg1, s32 arg2)
{
    ObjA00195270 *o;
    VEnt00195270 *e;
    char *p;

    o = (ObjA00195270 *)func_0017C870(arg1);
    e = (VEnt00195270 *)((char *)o->vtbl + 0x4E8);
    p = (char *)e->fn((char *)o + e->delta) + 0xF00;
    func_00319740(p, arg2);
    return func_00319700((Obj00370D70 *)p);
}
