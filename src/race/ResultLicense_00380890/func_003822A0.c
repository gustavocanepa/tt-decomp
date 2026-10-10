#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381CB8(s8, s32);                      /* extern */

struct func_003822A0_arg0 {
    s8 unk0;
    char pad1[0x9];
    s16 unkA;
    char padC[0xF];
    s8 unk1B;
};

void func_003822A0(struct func_003822A0_arg0 *arg0, s16 arg1) {
    arg0->unkA = arg1;
    arg0->unk1B = func_00381CB8(arg0->unk0, 0);
}
