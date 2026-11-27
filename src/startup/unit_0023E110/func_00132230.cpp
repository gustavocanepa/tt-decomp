#include "types.h"

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00406900(s32 arg0);

extern "C" s32 func_00132230(Obj *arg0) {
    return func_00406900(arg0->unk14);
}
