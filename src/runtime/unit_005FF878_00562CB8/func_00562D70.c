#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D70_arg0 {
    char pad0[0x116C];
    s32 unk116C;
};

void func_00562D70(struct func_00562D70_arg0 *arg0, s32 arg1) {
    arg0->unk116C = arg1;
}
