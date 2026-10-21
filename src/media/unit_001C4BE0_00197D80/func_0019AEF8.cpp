#include "types.h"

struct Obj {
    char pad[0x2C];
    s32 unk2C;
    s32 unk30;
};

extern "C" s32 func_0019AEF8(Obj *arg0) {
    s32 temp_v1 = arg0->unk2C;

    if (temp_v1 != 0) {
        return temp_v1;
    }
    return arg0->unk30;
}
