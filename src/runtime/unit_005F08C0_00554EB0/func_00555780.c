#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555780_arg0 {
    char pad0[0x178];
    s32 unk178;
};

void func_00555780(struct func_00555780_arg0 *arg0, s32 arg1) {
    arg0->unk178 = arg1;
}
