#include "types.h"

struct Obj {
    char pad0[0x18];
    u8 value;
};

extern "C" s32 func_0040D360(Obj *self);

extern "C" s32 func_0040D3D8(Obj *self, s32 v) {
    if (v >= func_0040D360(self)) {
        return 0;
    }
    self->value = v;
    return 1;
}
