#include "types.h"

struct Obj {
    char pad[0x78];
    s32 unk78;
};

extern "C" void func_00562628(struct Obj *arg0, f32 arg1) {
    arg0->unk78 = (s32)(arg1 * 128.0f);
}
