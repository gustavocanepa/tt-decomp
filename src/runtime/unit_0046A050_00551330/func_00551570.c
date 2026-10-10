#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551570_arg0 {
    char pad0[0xE410];
    s32 unkE410;
};

void func_00551570(struct func_00551570_arg0 *arg0, s32 arg1) {
    arg0->unkE410 = arg1;
}
