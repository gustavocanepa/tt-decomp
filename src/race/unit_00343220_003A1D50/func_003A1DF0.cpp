#include "types.h"

struct S003471A8 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" s32 func_002F8C28(s32 arg0, s32 arg1);

extern "C" s32 func_003A1DF0(struct S003471A8 **arg0, s32 arg1) {
    return func_002F8C28(arg1, (*arg0)->unk14);
}
