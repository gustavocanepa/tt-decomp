#include "types.h"

struct Node {
    char pad0[0x4];
    s32 unk4;
};

struct Obj {
    char pad0[0x18];
    s32 unk18;
    char pad1[0x4840 - 0x18 - 4];
    Node *unk2880;
    char pad2[0x4854 - 0x4840 - 4];
    s32 unk2894;
};

extern "C" void func_0036BCE0(Obj *arg0, s32 arg1) {
    Node *temp_v0;

    temp_v0 = arg0->unk2880;
    arg0->unk2894 = arg1;
    arg0->unk18 = arg1;
    if (temp_v0 != 0) {
        temp_v0->unk4 = arg1;
    }
}
