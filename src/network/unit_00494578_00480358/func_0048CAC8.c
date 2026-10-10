#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CAC8_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

void func_0048CAC8(struct func_0048CAC8_arg0 *arg0, s32 arg1) {
    arg0->unk5C = arg1;
}
