#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005509C0_arg0 {
    char pad0[0xD08];
    s32 unkD08;
};

void func_005509C0(struct func_005509C0_arg0 *arg0, s32 arg1) {
    arg0->unkD08 = arg1;
}
