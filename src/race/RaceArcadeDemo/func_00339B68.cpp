#include "types.h"

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char D_005CBCD0[];

extern "C" void func_003391D8(Obj *self, int flags);
extern "C" void RacePause__structor_1(void *self, int flags);
extern "C" void func_0050E1A8(void *p);

extern "C" void func_00339B68(Obj *self, int flags) {
    self->vtbl = D_005CBCD0;
    RacePause__structor_1((char *)self + 0x39AC0, 2);
    func_003391D8(self, 0);
    if (flags & 1) {
        return func_0050E1A8(self);
    }
}
