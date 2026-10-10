#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562478_arg0 {
    char pad0[0x1718];
    s32 unk1718;
};

void func_00562478(struct func_00562478_arg0 *arg0, s32 arg1) {
    arg0->unk1718 = arg1;
}
