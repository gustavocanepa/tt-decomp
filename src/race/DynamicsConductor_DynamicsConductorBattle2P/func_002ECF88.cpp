#include "types.h"

struct Obj {
    char pad[0x168];
    u8 ids[2];
};

extern u8 D_00582E70[];

extern "C" void func_002ECF88(Obj *self) {
    u32 i;
    for (i = 0; i < 2; i++)
        self->ids[i] = self->ids[i] < 8 ? D_00582E70[self->ids[i]] : self->ids[i];
}
