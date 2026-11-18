#include "types.h"

struct Obj003BB958 {
    char pad0[0x40];
    s32 unk40;
};

extern "C" s32 func_003709A0(s32 arg0, s32 arg1);

extern "C" s32 func_00370980(struct Obj003BB958 *arg0, struct Obj003BB958 *arg1) {
    return func_003709A0(arg0->unk40, arg1->unk40);
}
