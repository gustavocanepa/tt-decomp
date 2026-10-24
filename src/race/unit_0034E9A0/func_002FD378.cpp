#include "types.h"

struct Obj {
    u8 pad[0x30];
    u8 unk30;
};

extern char D_00582FF0[];

extern "C" void *func_002FD378(Obj *arg0) {
    return D_00582FF0 + arg0->unk30 * 0x54;
}
