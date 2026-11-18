#include "types.h"

struct Obj {
    void *vtbl;
    char pad[0x17C];
    s32 m180;
    s32 sub;
};

extern char D_005CA1D8[];
extern "C" Obj *func_003216C0(Obj *);
extern "C" void func_00387D70(s32 *);

extern "C" void func_003265E0(Obj *self) {
    s32 *p = &self->m180;
    func_003216C0(self);
    self->vtbl = D_005CA1D8;
    func_00387D70(&self->sub);
    *p = 0;
}
