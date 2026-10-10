#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005619E0_arg0 {
    char pad0[0x2A];
    s8 unk2A;
};

void func_005619E0(struct func_005619E0_arg0 *arg0, s8 arg1) {
    arg0->unk2A = arg1;
}
