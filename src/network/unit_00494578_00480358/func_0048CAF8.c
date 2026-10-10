#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CAF8_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void func_0048CAF8(struct func_0048CAF8_arg0 *arg0, s32 arg1) {
    arg0->unk6C = arg1;
}
