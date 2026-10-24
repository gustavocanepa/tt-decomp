#include "types.h"

struct Obj {
    char pad0[0x48];
    u16 unk48;
    char pad48[0x181 - 0x4A];
    s8 unk141;
};

extern "C" s8 func_0019E848(struct Obj *arg0) {
    u16 flag = arg0->unk48 & 1;
    if ((flag & 0xFFFF) == 0) {
        return -1;
    }
    return arg0->unk141;
}
