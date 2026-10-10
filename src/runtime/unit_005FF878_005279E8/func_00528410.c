#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528410_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_00528410(struct func_00528410_arg0 *arg0, s32 arg1) {
    arg0->unk40 = arg1;
}
