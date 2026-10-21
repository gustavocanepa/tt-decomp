#include "types.h"

struct Obj {
    char pad[0x12C0];
    s32 v[2];
};

extern "C" s32 func_003D10F8(Obj *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (self->v[i] < 0)
            return 0;
    }
    return 1;
}
