#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546478_arg0 {
    char pad0[0x104];
    s32 unk104;
};

void func_00546478(struct func_00546478_arg0 *arg0, s32 arg1) {
    arg0->unk104 = arg1;
}
