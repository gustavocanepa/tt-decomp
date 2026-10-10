#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546BC0_arg0 {
    char pad0[0x110];
    s32 unk110;
};

void func_00546BC0(struct func_00546BC0_arg0 *arg0, s32 arg1) {
    arg0->unk110 = arg1;
}
