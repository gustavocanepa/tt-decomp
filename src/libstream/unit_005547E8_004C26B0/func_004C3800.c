#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C3800_arg1 {
    char pad0[0x44];
    s32 unk44;
};

void func_004C3800(s32 arg0, struct func_004C3800_arg1 *arg1) {
    s32 *temp_a0;

    temp_a0 = arg0 + (arg1->unk44 * 0x1C);
    if (*temp_a0 == arg1) {
        *temp_a0 = 0;
    }
}
