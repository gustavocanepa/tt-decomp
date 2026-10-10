#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562938_arg0 {
    char pad0[0x1100];
    s32 unk1100;
};

void func_00562938(struct func_00562938_arg0 *arg0, s32 arg1) {
    arg0->unk1100 = arg1;
}
