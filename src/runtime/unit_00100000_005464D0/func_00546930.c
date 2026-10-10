#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546930_arg0 {
    char pad0[0x58];
    s32 unk58;
};

void func_00546930(struct func_00546930_arg0 *arg0, s32 arg1) {
    arg0->unk58 = arg1;
}
