#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00544260_arg0 {
    char pad0[0x884];
    s32 unk884;
};

void func_00544260(struct func_00544260_arg0 *arg0, s32 arg1) {
    arg0->unk884 = arg1;
}
