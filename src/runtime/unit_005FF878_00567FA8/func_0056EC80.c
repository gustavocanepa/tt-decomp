#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056EC80_arg0 {
    char pad0[0x1A88];
    s32 unk1A88;
};

void func_0056EC80(struct func_0056EC80_arg0 *arg0, s32 arg1) {
    arg0->unk1A88 = arg1;
}
