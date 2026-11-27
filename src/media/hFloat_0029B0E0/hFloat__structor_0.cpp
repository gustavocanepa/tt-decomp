#include "types.h"

extern char D_005C4390[];
extern "C" void *func_002A7618(void *);

struct hFloat { s32 m0; char *vtbl; s32 m8, mC; float v; };

extern "C" void *hFloat__structor_0(hFloat *self, float v) {
    void *r = func_002A7618(self);
    self->vtbl = D_005C4390;
    self->v = v;
    return r;
}
