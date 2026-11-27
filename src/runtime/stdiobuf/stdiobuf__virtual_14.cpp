#include "types.h"

struct Obj {
    char pad[0x58];
    s32 unk58;
};

extern "C" void func_004F5858(s32 arg0);

extern "C" void stdiobuf__virtual_14(struct Obj *arg0) {
    func_004F5858(arg0->unk58);
}
