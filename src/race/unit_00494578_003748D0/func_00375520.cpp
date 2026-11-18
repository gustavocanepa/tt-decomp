#include "types.h"

struct Sub {
    char data[4];
};

struct Obj {
    char pad[0xDF0];
    Sub sub;
};

extern "C" void func_003749C0(Obj *self);
extern "C" void func_003CD4B0(Sub *a, Sub *b);

extern "C" void func_00375520(Obj *self, Obj *other) {
    func_003749C0(self);
    func_003CD4B0(&self->sub, &other->sub);
}
