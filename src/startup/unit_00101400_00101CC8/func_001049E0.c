#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00478310(s32);                         /* extern */

struct func_001049E0_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
};

void func_001049E0(struct func_001049E0_arg0 *arg0, s32 arg1) {
    if (arg0->unk34 != 0) {
        func_00478310(arg0->unk0);
    }
    arg0->unk0 = arg1;
    arg0->unk34 = 0;
}
