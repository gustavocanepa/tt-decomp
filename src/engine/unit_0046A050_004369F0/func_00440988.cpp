#include "types.h"

struct Inner {
    void *unk0;
    s32 unk4;
};

struct Obj {
    char pad[0x2C];
    struct Inner inner;
};

extern "C" void func_004409B8(struct Obj *arg0, void *arg1, void *arg2, s32 arg3);

extern "C" void func_00440988(struct Obj *arg0, void *arg1) {
    struct Inner *temp_a2 = &arg0->inner;

    if (temp_a2->unk4 != 0) {
        func_004409B8(arg0, arg1, temp_a2->unk0, 1);
    }
}
