#include "types.h"

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" void func_00562708(struct Obj *arg0, f32 arg1) {
    arg0->unk8C = (s32)(arg1 * 128.0f);
}
