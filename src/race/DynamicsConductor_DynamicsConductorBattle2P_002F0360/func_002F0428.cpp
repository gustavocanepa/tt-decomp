#include "types.h"

struct Owner {
    char pad0[0xF4];
    char sound[4];
};

struct Obj {
    Owner *owner;
    char pad4[0x20A44 - 4];
    u16 timer;
};

extern "C" void func_0036C908(void *sound, int a, int b, int c);

extern "C" void func_002F0428(Obj *self) {
    if (self->timer) {
        if (--self->timer == 0)
            func_0036C908(self->owner->sound, 1, 0, 0);
    }
}
