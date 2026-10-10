#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00557600_arg0 {
    char pad0[0x40];
    s8 unk40;
};

void func_00557600(struct func_00557600_arg0 *arg0, s8 arg1) {
    arg0->unk40 = arg1;
}
