#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F5650(s32, s32);                /* extern */
s32 func_004F56E8(s8 *, s32);                   /* extern */
s8 *func_004F7D98(s32);                             /* extern */

struct func_004F6798_arg0 {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
};

void func_004F6798(struct func_004F6798_arg0 *arg0, s8 *arg1) {
    s8 *temp_v0;

    if ((arg1 != NULL) && (*arg1 != 0)) {
        func_004F56E8(arg1, arg0->unkC);
        func_004F56E8((s8 *)(s32)": ", arg0->unkC);
    }
    temp_v0 = func_004F7D98(arg0->unk0);
    if (temp_v0 != NULL) {
        func_004F56E8(temp_v0, arg0->unkC);
    }
    func_004F5650(0xA, arg0->unkC);
}
