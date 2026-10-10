#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528400_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_00528400(struct func_00528400_arg0 *arg0, s32 arg1) {
    arg0->unk3C = arg1;
}
