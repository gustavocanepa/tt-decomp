#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558860_arg0 {
    char pad0[0x20];
    s8 unk20;
};

void func_00558860(struct func_00558860_arg0 *arg0, s8 arg1) {
    arg0->unk20 = arg1;
}
