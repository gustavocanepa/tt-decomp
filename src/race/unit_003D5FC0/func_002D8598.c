#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003EB020(s32);                             /* extern */

struct func_002D8598_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[0x78];
    s32 unk9C;
};

void func_002D8598(struct func_002D8598_arg0 *arg0, s32 arg1) {
    if (((arg0->unk1C == 0) || (arg0->unk20 != 0)) && (func_003EB020(arg1) & 0x8003)) {
        arg0->unk9C = 3;
    }
}
