#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560D40_arg0 {
    char pad0[0x28];
    s32 unk28;
};

void func_00560D40(struct func_00560D40_arg0 *arg0, s32 arg1) {
    arg0->unk28 = arg1;
}
