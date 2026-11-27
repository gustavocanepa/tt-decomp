#include "types.h"

struct C { char pad[0xC]; u8 unkC; };
struct B { char pad[0x2C]; C *unk14; };

extern B *D_00586EF4;

extern "C" u8 func_00416060(void) {
    return D_00586EF4->unk14->unkC;
}
