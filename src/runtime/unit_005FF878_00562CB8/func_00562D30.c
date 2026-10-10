#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D30_arg0 {
    char pad0[0x115C];
    s32 unk115C;
};

void func_00562D30(struct func_00562D30_arg0 *arg0, s32 arg1) {
    arg0->unk115C = arg1;
}
