#include "types.h"

struct Obj {
    void *vtbl;
    char pad[0x18C];
    s32 a190;
    s32 pad194;
    s32 a198;
    char pad19c[0xC];
    s32 a1a8;
};

extern char D_005C9D90[];
extern "C" Obj *func_003216C0(Obj *);

extern "C" Obj *func_003250B0(Obj *self) {
    Obj *r = func_003216C0(self);
    self->vtbl = D_005C9D90;
    self->a190 = 0;
    self->a198 = 0;
    self->a1a8 = 0;
    return r;
}
