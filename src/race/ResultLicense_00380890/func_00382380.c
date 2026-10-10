#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381DF8(s8, s32);                      /* extern */

struct func_00382380_arg0 {
    s8 unk0;
    char pad1[0x11];
    s16 unk12;
    char pad14[0xB];
    s8 unk1F;
};

void func_00382380(struct func_00382380_arg0 *arg0, s16 arg1) {
    arg0->unk12 = arg1;
    arg0->unk1F = func_00381DF8(arg0->unk0, 0);
}
