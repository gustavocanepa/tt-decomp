#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct func_00376C18_arg0;

struct Obj_00389ED8 {
    char pad0[0x64];
    VEntry *vt64;
    char pad68[4];
    void *p6C;
    char pad70[0xDA4 - 0x70];
    s32 ce0;
};

extern "C" void func_00376C18(struct func_00376C18_arg0 *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_0033C5A8(Obj_00389ED8 *self, s32 arg1, f32 fparg0, f32 fparg1) {
    self->ce0 = arg1;
    if (fparg0 == 0.0f && fparg1 == 0.0f) {
        VEntry *e = (VEntry *)((char *)self->vt64 + 0x280);
        e->fn((char *)self + e->delta);
        return;
    }
    func_00376C18((struct func_00376C18_arg0 *)self->p6C, fparg0, fparg1);
}
