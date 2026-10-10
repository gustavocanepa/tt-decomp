#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005441E0_arg0 {
    char pad0[0x87C];
    s32 unk87C;
};

void func_005441E0(struct func_005441E0_arg0 *arg0, s32 arg1) {
    arg0->unk87C = arg1;
}
