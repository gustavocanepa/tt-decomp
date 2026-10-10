#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020D250();                            /* extern */
s32 func_00255EA8(void *, s32);                 /* extern */
s32 mListBox__leaveDragMode(void *, s32);                 /* extern */

struct mListBox__virtual_81_arg0 {
    char pad0[0x14C];
    s32 unk14C;
    char pad150[0x4];
    s32 unk154;
};

s32 mListBox__onFocusLeave(struct mListBox__virtual_81_arg0 *arg0, s32 arg1) {
    s32 temp_s1;

    func_0020D250();
    temp_s1 = arg0->unk154;
    mListBox__leaveDragMode(arg0, arg1);
    if (temp_s1 >= 0) {
        func_00255EA8(arg0, temp_s1);
    }
    func_00255EA8(arg0, arg0->unk14C);
    return 1;
}
