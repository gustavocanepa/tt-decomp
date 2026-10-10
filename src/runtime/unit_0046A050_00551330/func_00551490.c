#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551490_arg0 {
    char pad0[0xE3E0];
    s32 unkE3E0;
};

void func_00551490(struct func_00551490_arg0 *arg0, s32 arg1) {
    arg0->unkE3E0 = arg1;
}
