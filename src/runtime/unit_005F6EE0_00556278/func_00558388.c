#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558388_arg0 {
    char pad0[0x44];
    s32 unk44;
};

void func_00558388(struct func_00558388_arg0 *arg0, s32 arg1) {
    arg0->unk44 = arg1;
}
