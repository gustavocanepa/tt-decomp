#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556228_arg0 {
    char pad0[0x2F];
    s8 unk2F;
};

void func_00556228(struct func_00556228_arg0 *arg0, s8 arg1) {
    arg0->unk2F = arg1;
}
