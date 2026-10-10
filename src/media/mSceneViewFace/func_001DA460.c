#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001DA460_arg0 {
    char pad0[0x48];
    s32 unk48;
};

void func_001DA460(struct func_001DA460_arg0 *arg0) {
    arg0->unk48 = (s32) (arg0->unk48 | 0x60);
}
