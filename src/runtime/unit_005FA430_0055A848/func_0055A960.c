#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A960_arg0 {
    char pad0[0x1780];
    s32 unk1780;
};

void func_0055A960(struct func_0055A960_arg0 *arg0, s32 arg1) {
    arg0->unk1780 = arg1;
}
