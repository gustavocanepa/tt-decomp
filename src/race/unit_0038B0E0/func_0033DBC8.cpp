#include "types.h"

struct VEntry_428 {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Sub_428 {
    char pad0[4];
    void *p4;
};

struct Mid_428 {
    char pad0[0x80];
    Sub_428 *p80;
    char pad1[0xD0 - 0x84];
    s32 fD0;
};

struct Obj_428 {
    char pad0[0x64];
    char *vt;
    char pad1[4];
    Mid_428 *f6C;
    char pad2[0xE400 - 0x70];
    s32 fE400;
    char pad3[0xE418 - 0xE404];
    s32 fE418;
};

extern "C" void RaceBasic__setPause(Obj_428 *arg0, s32 arg1);
extern "C" void CourseData__setPause(void *self, s32 on);
extern "C" void PauseBase__setTimeLimit(void *arg0, s32 arg1);

extern "C" void func_0033DBC8(Obj_428 *self, s32 arg1) {
    s32 v = arg1;
    if (v == 0) {
        v = *(s32 *)((char *)self + 0xE4C0);
    }
    *(s32 *)((char *)self + 0xE4D8) = v;
    if (v != 0) {
        PauseBase__setTimeLimit((void *)v, self->f6C->fD0);
        RaceBasic__setPause(self, 1);
        VEntry_428 *e = (VEntry_428 *)(self->vt + 0x2E0);
        e->fn((char *)self + e->delta);
        CourseData__setPause(self->f6C->p80->p4, 1);
    }
}
