#include "types.h"

struct mScrollBase {
    char pad0[0xD4];
    s32 unkB0;
    s32 unkB4;
};

struct mScrollBaseArg2 {
    char pad0[0x20];
    u16 unk20;
};

extern "C" s32 func_0020BC90(struct mScrollBase *self, s32 arg1, void *arg2);
extern "C" s32 func_00276E80(s32 arg0, s32 arg1, void *arg2);
extern "C" s32 func_00276FC0(s32 arg0, s32 arg1, void *arg2);

extern "C" s32 func_00274E50(struct mScrollBase *arg0, s32 arg1, struct mScrollBaseArg2 *arg2) {
    s32 r = func_0020BC90(arg0, arg1, arg2);
    if (arg2->unk20 != 1) {
        return r;
    }
    {
        s32 temp_a0 = arg0->unkB0;
        if (temp_a0 == 0) {
            return 0;
        }
        if (arg0->unkB4 != 0) {
            return func_00276E80(temp_a0, arg1, arg2);
        }
        return func_00276FC0(temp_a0, arg1, arg2);
    }
}
