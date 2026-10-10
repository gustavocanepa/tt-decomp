#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542878_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void func_00542878(struct func_00542878_arg0 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}
