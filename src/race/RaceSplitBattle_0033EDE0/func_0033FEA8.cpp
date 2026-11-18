#include "types.h"

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char D_005CCFE0[];

extern "C" void func_0033EAE8(Obj *self, int flags);
extern "C" void func_00358700(void *self, int flags);
extern "C" void func_0050E1A8(void *p);

extern "C" void func_0033FEA8(Obj *self, int flags) {
    self->vtbl = D_005CCFE0;
    func_00358700((char *)self + 0x3DD00, 2);
    func_0033EAE8(self, 0);
    if (flags & 1) {
        return func_0050E1A8(self);
    }
}
