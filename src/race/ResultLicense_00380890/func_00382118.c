#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381B28(s8, s32);                      /* extern */

struct func_00382118_arg0 {
    s8 unk0;
    s8 unk1;
    char pad2[0x12];
    s8 unk14;
};

void func_00382118(struct func_00382118_arg0 *arg0, s8 arg1) {
    arg0->unk1 = arg1;
    arg0->unk14 = func_00381B28(arg0->unk0, 0);
}
