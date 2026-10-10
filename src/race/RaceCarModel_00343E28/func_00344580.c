#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00344580_arg0 {
    char pad0[0x3548];
    s32 unk3548;
    s32 unk354C;
};

void func_00344580(struct func_00344580_arg0 *arg0, s32 arg1) {
    arg0->unk3548 = arg1;
    arg0->unk354C = 0;
}
