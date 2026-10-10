#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F04F0_arg0 {
    char pad0[0x2392E];
    u8 unk2392E;
};

s32 func_002F04F0(struct func_002F04F0_arg0 *arg0) {
    return arg0->unk2392E == 0;
}
