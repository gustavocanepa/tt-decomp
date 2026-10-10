#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CA88_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_0048CA88(struct func_0048CA88_arg0 *arg0, s32 arg1) {
    arg0->unk50 = arg1;
}
