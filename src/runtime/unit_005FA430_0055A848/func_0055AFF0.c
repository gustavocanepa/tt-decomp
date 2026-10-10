#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055AFF0_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_0055AFF0(struct func_0055AFF0_arg0 *arg0, s32 arg1) {
    arg0->unk30 = arg1;
}
