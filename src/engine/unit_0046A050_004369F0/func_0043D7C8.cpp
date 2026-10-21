#include "types.h"

struct Val { s32 type; f32 v; };
extern "C" void func_0043D510(Val *);

extern "C" void func_0043D7C8(Val *self, f32 v) {
    s32 type = 6;
    func_0043D510(self);
    self->type = type;
    self->v = v;
}
