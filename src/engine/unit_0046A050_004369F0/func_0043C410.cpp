#include "types.h"

struct Inner {
    char pad[0x70];
    s32 unk70;
};

struct Obj {
    Inner *inner;
};

extern "C" void func_0043C410(Obj *arg0) {
    arg0->inner->unk70 = 1;
}
