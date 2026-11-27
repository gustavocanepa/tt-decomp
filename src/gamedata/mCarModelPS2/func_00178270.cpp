#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_0050E1A8(void *p);

extern "C" void func_00178270(Obj *self, s32 flags) {
    self->unk8 = 0;
    self->unk4 = 0;
    self->unk10 = 0;
    if (flags & 1) {
        return func_0050E1A8(self);
    }
}
