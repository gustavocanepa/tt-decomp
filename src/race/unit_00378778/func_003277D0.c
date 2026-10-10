#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003277D0_arg0 {
    char pad0[0x184];
    s32 unk184;
};

void func_003277D0(struct func_003277D0_arg0 *arg0, s32 arg1) {
    arg0->unk184 = arg1;
}
