#include "types.h"

struct Obj {
    char pad[0xAC];
    u32 unk98;
};

extern "C" s32 func_0020E9F8(Obj *arg0, s32 arg1) {
    u32 t = (arg0->unk98 >> 8) & 0xF;
    return (t & arg1) != 0;
}
