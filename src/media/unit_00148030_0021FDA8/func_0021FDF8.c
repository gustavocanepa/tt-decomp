#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021FDF8_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_0021FDF8(struct func_0021FDF8_arg0 *arg0, s32 arg1) {
    if (arg0->unk64 != arg1) {
        arg0->unk64 = arg1;
        arg0->unk68 = 0;
    }
}
