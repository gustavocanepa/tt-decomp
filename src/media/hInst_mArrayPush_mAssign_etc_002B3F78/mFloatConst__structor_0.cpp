#include "types.h"

struct Obj {
    s32 a;
    void *vtbl;
    f32 f;
};

extern char D_005C6D00[];
extern "C" Obj *func_002C0EB0(Obj *);

extern "C" Obj *mFloatConst__structor_0(Obj *self, f32 f) {
    Obj *r = func_002C0EB0(self);
    self->vtbl = D_005C6D00;
    self->f = f;
    return r;
}
