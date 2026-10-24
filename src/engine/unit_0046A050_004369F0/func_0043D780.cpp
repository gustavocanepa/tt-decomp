#include "types.h"

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);

extern "C" void func_0043D780(Val *self, s32 v) {
    s32 type = 5;
    func_0043D510(self);
    self->type = type;
    self->v = v;
}
