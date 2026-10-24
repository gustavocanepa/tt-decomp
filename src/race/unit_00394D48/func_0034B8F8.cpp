#include "types.h"

struct Node {
    char pad[8];
    struct Node *unk8;
};

extern "C" void func_002E14B0(struct Node *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_0034B8F8(struct Node *arg0, s32 arg1, s32 arg2) {
    struct Node *temp_v0 = arg0->unk8;

    if (temp_v0 != 0) {
        func_002E14B0(temp_v0, arg1, 0, 0, arg2);
    }
}
