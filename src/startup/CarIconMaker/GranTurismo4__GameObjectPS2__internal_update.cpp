#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x64];
    char *vt;
    s32 f68;
};

extern "C" void func_004A4D68(s32 a0);
extern "C" void func_004A4DD8(s32 a0);
extern "C" void func_00108B78(struct Obj *self);

extern "C" void GranTurismo4__GameObjectPS2__internal_update(struct Obj *self)
{
    s32 zero;
    s32 flag = 0;
    s32 v;

    func_004A4D68((s32)self);

    v = self->f68;
    zero = (v == 0);
    if (!zero) {
        self->f68 = v + 1;
        flag = (v + 1) >= 4;
    }

    func_004A4DD8((s32)self);

    {
        VEntry *e = (VEntry *)(self->vt + 0x30);
        e->fn((char *)self + e->delta);
    }

    if (zero) {
        VEntry *a = (VEntry *)(self->vt + 0x28);
        a->fn((char *)self + a->delta);
        VEntry *b = (VEntry *)(self->vt + 0x38);
        b->fn((char *)self + b->delta);
        return;
    }

    if (flag) {
        func_00108B78(self);
    }
}
