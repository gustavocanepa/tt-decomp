#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00205D10(s32);                         /* extern */
s32 func_00205D70(s32);                         /* extern */

struct func_00254000_arg0 {
    char pad0[0xD4];
    s32 unkD4;
    char padD8[0x6C];
    s32 unk144;
};

void func_00254000(struct func_00254000_arg0 *arg0) {
    s32 temp_a0;

    temp_a0 = arg0->unk144;
    if (arg0->unkD4 == 0) {
        func_00205D10(temp_a0);
        return;
    }
    func_00205D70(temp_a0);
}
