#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E318_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_0052E318(struct func_0052E318_arg0 *arg0, s32 arg1) {
    arg0->unk24 = arg1;
}
