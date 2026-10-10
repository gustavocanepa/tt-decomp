#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381C48(s8, s32);                      /* extern */

struct func_00382230_arg0 {
    s8 unk0;
    char pad1[0x5];
    s16 unk6;
    char pad8[0x11];
    s8 unk19;
};

void func_00382230(struct func_00382230_arg0 *arg0, s16 arg1) {
    arg0->unk6 = arg1;
    arg0->unk19 = func_00381C48(arg0->unk0, 0);
}
