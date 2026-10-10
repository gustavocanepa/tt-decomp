#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00544250_arg0 {
    char pad0[0x880];
    s32 unk880;
};

void func_00544250(struct func_00544250_arg0 *arg0, s32 arg1) {
    arg0->unk880 = arg1;
}
