#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005632E0_arg0 {
    char pad0[0x94];
    s32 unk94;
};

void func_005632E0(struct func_005632E0_arg0 *arg0, s32 arg1) {
    arg0->unk94 = arg1;
}
