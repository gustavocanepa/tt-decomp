#include "types.h"

struct Obj {
    s32 a;
    s32 b;
    f32 t;
};

extern char D_00582E98[];
extern "C" f32 func_002F5018(void *);

extern "C" s32 func_002E4918(Obj *self) {
    return func_002F5018(D_00582E98) <= self->t;
}
