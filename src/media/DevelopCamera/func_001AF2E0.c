#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AF2E0_arg0 {
    char pad0[0x14080];
    s32 unk14080;
};

void *func_001AF2E0(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        return arg0 + ((1 - ((struct func_001AF2E0_arg0 *)arg0)->unk14080) * 0x250) + 0x13BE0;
    }
    return arg0 + (((struct func_001AF2E0_arg0 *)arg0)->unk14080 * 0x250) + 0x13BE0;
}
