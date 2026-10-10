#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381C28(s8, s32);                      /* extern */

struct func_003821F8_arg0 {
    s8 unk0;
    char pad1[0x4];
    s8 unk5;
    char pad6[0x12];
    s8 unk18;
};

void func_003821F8(struct func_003821F8_arg0 *arg0, s8 arg1) {
    arg0->unk5 = arg1;
    arg0->unk18 = func_00381C28(arg0->unk0, 0);
}
