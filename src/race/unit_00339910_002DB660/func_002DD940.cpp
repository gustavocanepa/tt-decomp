#include "types.h"

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" f32 func_002DD940(Obj *arg0) {
    char *p = (char *)arg0 + arg0->unk8C * 0x44;
    return *(f32 *)(p + 0x38);
}
