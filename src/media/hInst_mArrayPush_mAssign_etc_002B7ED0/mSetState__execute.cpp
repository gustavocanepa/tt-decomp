#include "types.h"

struct Obj0 {
    char pad0[8];
    s32 unk8;
};

struct Elem {
    char pad[0x38];
    s32 unk38;
};

struct mSetState__virtual_08_arg1 {
    char pad0[0x34];
    s32 unk34;
    char pad38[0x10];
    s32 unk48;
};

extern "C" void mSetState__execute(struct Obj0 *arg0, void *arg1) {
    s32 temp_v0 = arg0->unk8;
    ((struct mSetState__virtual_08_arg1 *)arg1)->unk34 = temp_v0;
    s32 temp_v1 = ((struct Elem *)((char *)arg1 + temp_v0 * 4))->unk38;
    ((struct mSetState__virtual_08_arg1 *)arg1)->unk48 = temp_v1;
}
