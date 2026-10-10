#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00478310(s32);                         /* extern */

struct func_00104BA8_arg0 {
    s32 unk0;
    char pad4[0x2C];
    s32 unk30;
    s32 unk34;
};

void func_00104BA8(struct func_00104BA8_arg0 *arg0) {
    if (arg0->unk34 != 0) {
        func_00478310(arg0->unk0);
    }
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    arg0->unk0 = -1;
}
