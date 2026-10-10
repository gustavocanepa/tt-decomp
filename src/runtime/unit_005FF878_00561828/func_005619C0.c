#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005619C0_arg0 {
    char pad0[0x28];
    s8 unk28;
};

void func_005619C0(struct func_005619C0_arg0 *arg0, s8 arg1) {
    arg0->unk28 = arg1;
}
