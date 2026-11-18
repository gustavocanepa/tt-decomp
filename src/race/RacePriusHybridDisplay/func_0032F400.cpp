#include "types.h"

struct Elem_003AA488 {
    char data[0x1D80];
};

struct Obj_003AA488 {
    Elem_003AA488 elems[2];
};

extern "C" void func_0032ECA8(Elem_003AA488 *e, f32 t);

extern "C" void func_0032F400(Obj_003AA488 *arg0, f32 t) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_0032ECA8(&arg0->elems[i], t);
    }
}
