#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381C08(s8, s32);                      /* extern */

struct func_003821C0_arg0 {
    s8 unk0;
    char pad1[0x3];
    s8 unk4;
    char pad5[0x12];
    s8 unk17;
};

void func_003821C0(struct func_003821C0_arg0 *arg0, s8 arg1) {
    arg0->unk4 = arg1;
    arg0->unk17 = func_00381C08(arg0->unk0, 0);
}
