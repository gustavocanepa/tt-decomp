#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005711C0_arg0 {
    char pad0[0x20];
    s8 *unk20;
};

void func_005711C0(struct func_005711C0_arg0 *arg0) {
    *arg0->unk20 = 0;
}
