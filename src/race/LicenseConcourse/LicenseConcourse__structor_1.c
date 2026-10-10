#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003C85B0(void *, s32);             /* extern */
s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D70E8[];
struct LicenseConcourse__structor_1_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x6C];
    s32 unk80;
};

void LicenseConcourse__structor_1(struct LicenseConcourse__structor_1_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk10 = (s32)D_005D70E8;
    temp_v1 = arg0->unk80;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    func_003C85B0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
