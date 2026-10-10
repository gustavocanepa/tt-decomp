#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001CDA30_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_001CDA30(struct func_001CDA30_arg0 *arg0, s32 arg1) {
    arg0->unk20 = arg1;
}
