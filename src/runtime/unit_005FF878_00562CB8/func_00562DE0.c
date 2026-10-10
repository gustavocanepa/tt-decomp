#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DE0_arg0 {
    char pad0[0x1184];
    s32 unk1184;
};

void func_00562DE0(struct func_00562DE0_arg0 *arg0, s32 arg1) {
    arg0->unk1184 = arg1;
}
