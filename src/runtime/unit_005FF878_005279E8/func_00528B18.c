#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B18_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_00528B18(struct func_00528B18_arg0 *arg0, s32 arg1) {
    arg0->unk8 = arg1;
}
