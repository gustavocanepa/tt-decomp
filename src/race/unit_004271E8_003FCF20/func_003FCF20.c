#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004558C0(s32);                             /* extern */

struct func_003FCF20_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_003FCF20(struct func_003FCF20_arg0 *arg0, s32 arg1) {
    arg0->unkC = func_004558C0(arg1);
}
