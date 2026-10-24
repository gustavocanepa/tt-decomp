#include "types.h"

struct Obj {
    char pad[0x18];
    s8 id;
};

extern "C" s32 func_0040D680(Obj *, s32, s32);

extern "C" s32 func_0040D640(Obj *self, s32 arg1) {
    if (self->id == -1)
        return 0;
    return func_0040D680(self, self->id, arg1);
}
