#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418618_arg0 {
    char pad0[0x33C];
    s32 unk33C;
};

void func_00418618(struct func_00418618_arg0 *arg0, s32 arg1) {
    arg0->unk33C = arg1;
}
