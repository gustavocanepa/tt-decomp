#include "types.h"

struct Obj {
    u8 pad[0x24];
    s32 unk24;
};

extern "C" void func_0038FB58(char *arg0, s32 arg1, s32 arg2);

extern "C" void func_00359638(Obj *arg0, s32 arg1) {
    func_0038FB58((char *)arg0 + 0x46, arg1, 0x20);
    arg0->unk24 = 0;
}
