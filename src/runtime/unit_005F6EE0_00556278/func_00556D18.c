#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556D18_arg0 {
    char pad0[0x68];
    s32 unk68;
};

void func_00556D18(struct func_00556D18_arg0 *arg0, s32 arg1) {
    arg0->unk68 = arg1;
}
