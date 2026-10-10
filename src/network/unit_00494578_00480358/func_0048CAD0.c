#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CAD0_arg0 {
    char pad0[0x60];
    s32 unk60;
};

void func_0048CAD0(struct func_0048CAD0_arg0 *arg0, s32 arg1) {
    arg0->unk60 = arg1;
}
