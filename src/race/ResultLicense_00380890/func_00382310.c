#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381D58(s8, s32);                      /* extern */

struct func_00382310_arg0 {
    s8 unk0;
    char pad1[0xD];
    s16 unkE;
    char pad10[0xD];
    s8 unk1D;
};

void func_00382310(struct func_00382310_arg0 *arg0, s16 arg1) {
    arg0->unkE = arg1;
    arg0->unk1D = func_00381D58(arg0->unk0, 0);
}
