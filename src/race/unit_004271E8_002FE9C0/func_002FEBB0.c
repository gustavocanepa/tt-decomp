#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FEBB0_arg0 {
    char pad0[0x2];
    u8 unk2;
};

s32 func_002FEBB0(struct func_002FEBB0_arg0 *arg0) {
    return arg0->unk2 == 1;
}
