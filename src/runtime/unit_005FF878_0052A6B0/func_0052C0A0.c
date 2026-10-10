#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052C0A0_arg0 {
    char pad0[0x114];
    s32 unk114;
};

void func_0052C0A0(struct func_0052C0A0_arg0 *arg0, s32 arg1) {
    arg0->unk114 = arg1;
}
