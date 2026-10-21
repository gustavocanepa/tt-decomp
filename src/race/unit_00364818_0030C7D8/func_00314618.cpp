#include "types.h"

struct Inner {
    char pad[0x32];
    u8 unk32;
};

struct Sub {
    char pad[0x540];
    s8 unk520;
};

struct Obj {
    char pad0[0x10];
    Inner *unk10;
};

extern "C" void func_00314618(Obj *arg0, int arg1) {
    u8 type = arg0->unk10->unk32;
    Sub *sub = (Sub *)((char *)arg0 + 0x104);
    if (type != 4 || arg1 != 0) {
        sub->unk520 = arg1;
    }
}
