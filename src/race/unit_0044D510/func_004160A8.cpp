#include "types.h"

struct Inner {
    char pad[0x11];
    u8 unk11;
};

struct Obj {
    char pad[0x2C];
    Inner *unk14;
};

extern "C" Obj *D_00586EF4;

extern "C" u8 func_004160A8(void) {
    return D_00586EF4->unk14->unk11;
}
