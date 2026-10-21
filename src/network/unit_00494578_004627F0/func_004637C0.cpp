#include "types.h"

struct Obj {
    char pad[0x3C];
    s32 unk3C;
};

extern "C" void *func_004637C0(Obj *arg0) {
    arg0->unk3C = 1;
    return (char *)arg0 + 0x28;
}
