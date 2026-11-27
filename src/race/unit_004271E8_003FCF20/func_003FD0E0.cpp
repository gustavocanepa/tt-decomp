#include "types.h"

struct Obj {
    char pad[0x10D0];
    s32 unk10D0;
    s32 unk10D4;
};

extern "C" s32 func_003FD070(s32 arg0, s32 arg1);

extern "C" s32 func_003FD0E0(struct Obj *arg0) {
    return func_003FD070(arg0->unk10D4, arg0->unk10D0);
}
