#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002BCAE0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void func_002BCAE0(struct func_002BCAE0_arg0 *arg0, s32 arg1) {
    arg0->unk14 = arg1;
    arg0->unk18 = arg1;
}
