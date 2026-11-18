#include "types.h"

struct Src {
    u8 pad[0x167];
    u8 unk167;
};

struct Dst {
    u8 pad[0x11D];
    u8 unk11D;
    u16 unk11E;
};

extern "C" void func_0040AB30(Src *arg0, Dst *arg1, u16 *arg2) {
    arg1->unk11D = arg0->unk167;
    arg1->unk11E = *arg2;
}
