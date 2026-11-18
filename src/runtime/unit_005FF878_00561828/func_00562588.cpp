#include "types.h"

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" void func_00562588(struct Obj *arg0, f32 arg1) {
    arg0->unk68 = (s32)(arg1 * 128.0f);
}
