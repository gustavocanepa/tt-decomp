#include "types.h"

struct Obj {
    char pad[0x64];
    u8 unk64;
    u8 unk65;
    u8 unk66;
};

extern "C" u8 *func_0041E698(Obj *arg0, u8 *arg1) {
    arg1[0] = arg0->unk64;
    arg1[1] = arg0->unk65;
    arg1[2] = arg0->unk66;
    arg1[3] = 0;
    return arg1;
}
