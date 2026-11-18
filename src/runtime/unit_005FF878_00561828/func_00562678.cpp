#include "types.h"

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00562678(struct Obj *arg0, f32 arg1) {
    arg0->unk80 = (s32)(arg1 * 128.0f);
}
