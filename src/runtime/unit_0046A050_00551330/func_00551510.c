#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551510_arg0 {
    char pad0[0xE3EC];
    s32 unkE3EC;
};

void func_00551510(struct func_00551510_arg0 *arg0, s32 arg1) {
    arg0->unkE3EC = arg1;
}
