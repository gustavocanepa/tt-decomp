#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541830_arg0 {
    char pad0[0x12C];
    s32 unk12C;
};

void func_00541830(struct func_00541830_arg0 *arg0, s32 arg1) {
    arg0->unk12C = arg1;
}
