#include "types.h"

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern void func_00393008(s32);

extern "C" void func_0034B958(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk10;
    if (temp_v0 != 0) {
        func_00393008(temp_v0);
    }
}
