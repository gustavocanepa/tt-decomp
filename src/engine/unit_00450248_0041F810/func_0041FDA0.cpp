#include "types.h"

struct Obj {
    char pad[0x2E];
    u16 size;
    char pad2[0x18];
    void *data;
};

extern "C" void *func_00567150(void *, void *, s32);

extern "C" void *func_0041FDA0(Obj *self, void *dst) {
    if (self->data == 0)
        return 0;
    return func_00567150(dst, self->data, self->size);
}
