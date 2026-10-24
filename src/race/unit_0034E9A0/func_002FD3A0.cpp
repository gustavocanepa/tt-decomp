#include "types.h"

struct Obj {
    u8 pad[0x30];
    u8 unk30;
};

struct Arg {
    unsigned char pad0[0x10];
    Obj *unk10;
};

extern char D_00582FF0[];

extern "C" void *func_002FD3A0(Arg *arg0) {
    return D_00582FF0 + arg0->unk10->unk30 * 0x54;
}
