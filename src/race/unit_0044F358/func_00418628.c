#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418628_arg0 {
    char pad0[0x330];
    s32 unk330;
};

void func_00418628(struct func_00418628_arg0 *arg0, s32 arg1) {
    arg0->unk330 = arg1;
}
