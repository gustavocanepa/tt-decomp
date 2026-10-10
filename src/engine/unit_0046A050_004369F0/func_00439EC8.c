/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */
s32 func_0046F0F8(s32);                     /* extern */
s32 func_00477DC0(u32);                         /* extern */
s32 func_00478C98(s32);                     /* extern */

struct func_00439EC8_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
};

void func_00439EC8(struct func_00439EC8_arg0 *arg0, u32 arg1) {
    u32 var_s1;

    var_s1 = arg1;
    if (arg0->unk14 == 0) {
        func_0043A180();
    }
    if (arg0->unkC != 0) {
        var_s1 = (var_s1 & 0xFFFFFF) | (arg0->unk24 << 0x18);
        func_00478C98(9);
    } else if ((arg0->unk0 != 0) && (arg0->unk4 == 0)) {
        if ((var_s1 >> 0x18) == 0x80) {
            func_0046F0F8(9);
        } else {
            func_00478C98(9);
        }
    }
    func_00477DC0(var_s1);
}
