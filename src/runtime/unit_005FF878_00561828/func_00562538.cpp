#include "types.h"

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" void func_00562538(struct Obj *arg0, f32 arg1) {
    arg0->unk60 = (s32)(arg1 * 128.0f);
}
