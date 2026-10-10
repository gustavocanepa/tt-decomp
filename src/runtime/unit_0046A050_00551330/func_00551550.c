#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551550_arg0 {
    char pad0[0xE3F4];
    s32 unkE3F4;
};

void func_00551550(struct func_00551550_arg0 *arg0, s32 arg1) {
    arg0->unkE3F4 = arg1;
}
