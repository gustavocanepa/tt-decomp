#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00457FD0_arg0 {
    char pad0[0xD80];
    s32 unkD80;
};

void func_00457FD0(struct func_00457FD0_arg0 *arg0, s32 arg1) {
    arg0->unkD80 = arg1;
}
