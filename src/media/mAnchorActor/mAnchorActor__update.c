#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00205C50(s32);                             /* extern */
s32 func_00205C80(s32, f32);                    /* extern */
f32 func_00205CB0(s32);                             /* extern */
s32 func_00205CE0(s32, f32);                    /* extern */

struct mAnchorActor__virtual_52_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    f32 unk50;
    f32 unk54;
    char pad58[0x4];
    s32 unk5C;
    s32 unk60;
};

s32 mAnchorActor__update(struct mAnchorActor__virtual_52_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    if (arg2 != 0) {
        temp_a0 = arg0->unk4C;
        if (temp_a0 != 0) {
            if (arg0->unk5C != 0) {
                func_00205C80(arg2, func_00205C50(temp_a0) + arg0->unk50);
            }
            if (arg0->unk60 != 0) {
                func_00205CE0(arg2, func_00205CB0(arg0->unk4C) + arg0->unk54);
            }
        }
    }
}
