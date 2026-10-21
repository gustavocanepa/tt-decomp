#include "types.h"

struct Obj {
    char pad[0x10];
    f32 unk10;
};

extern "C" s32 hFloat__toInt(Obj *arg0) {
    return (s32)arg0->unk10;
}
