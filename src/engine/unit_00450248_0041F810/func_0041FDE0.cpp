#include "types.h"

struct Obj {
    char pad0[0x26];
    u16 size;
    char pad28[0x28];
    void *data;
};

extern "C" void *func_005671D0(void *dst, const void *src, u16 n);

extern "C" void *func_0041FDE0(Obj *self, void *dst) {
    if (self->data == 0) {
        return 0;
    }
    return func_005671D0(dst, self->data, self->size);
}
