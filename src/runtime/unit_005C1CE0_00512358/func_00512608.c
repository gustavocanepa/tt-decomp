#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00512608_arg0 {
    char pad0[0x304];
    s32 unk304;
};

void func_00512608(struct func_00512608_arg0 *arg0, s32 arg1) {
    arg0->unk304 = arg1;
}
