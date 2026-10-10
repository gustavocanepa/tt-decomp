#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518460_arg0 {
    char pad0[0x188];
    s32 unk188;
};

void func_00518460(struct func_00518460_arg0 *arg0, s32 arg1) {
    arg0->unk188 = arg1;
}
