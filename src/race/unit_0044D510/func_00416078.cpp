#include "types.h"

struct Inner {
    char pad[0xD];
    u8 unkD;
};

struct Obj {
    char pad[0x2C];
    Inner *unk14;
};

extern "C" Obj *D_00586EF4;

extern "C" u8 func_00416078(void) {
    return D_00586EF4->unk14->unkD;
}
