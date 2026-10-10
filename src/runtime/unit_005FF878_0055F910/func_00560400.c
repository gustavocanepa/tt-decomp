#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560400_arg0 {
    char pad0[0x144];
    s32 unk144;
};

void func_00560400(struct func_00560400_arg0 *arg0, s32 arg1) {
    arg0->unk144 = arg1;
}
