#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004E54D0_arg0 {
    char pad0[0x48];
    s16 unk48;
};

s32 func_004E54D0(struct func_004E54D0_arg0 *arg0, s32 arg1) {
    arg0->unk48 = (s16) (arg1 + 1);
    return 0;
}
