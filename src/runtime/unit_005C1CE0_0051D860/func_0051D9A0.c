#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051D9A0_arg0 {
    char pad0[0x1F70];
    s32 unk1F70;
};

void func_0051D9A0(struct func_0051D9A0_arg0 *arg0, s32 arg1) {
    arg0->unk1F70 = arg1;
}
