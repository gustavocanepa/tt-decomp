#include "types.h"

struct Obj3F1750 {
    char pad[0x1C2];
    u8 unk1C2;
};

extern "C" s32 func_0039EF20(Obj3F1750 *arg0) {
    return arg0->unk1C2 == 0;
}
