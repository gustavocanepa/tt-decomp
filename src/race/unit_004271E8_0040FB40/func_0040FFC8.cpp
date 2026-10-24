#include "types.h"

struct Local {
    char pad[0x10];
    u8 unk10;
    char pad2[0x20 - 0x10 - 1];
};

extern "C" void func_0040FED0(s32 arg0, Local *arg1);

extern "C" u8 func_0040FFC8(s32 arg0) {
    Local loc;
    func_0040FED0(arg0, &loc);
    return loc.unk10;
}
