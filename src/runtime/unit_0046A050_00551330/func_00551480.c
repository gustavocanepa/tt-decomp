#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551480_arg0 {
    char pad0[0xE3FC];
    s32 unkE3FC;
};

void func_00551480(struct func_00551480_arg0 *arg0, s32 arg1) {
    arg0->unkE3FC = arg1;
}
