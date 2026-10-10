#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A80_arg0 {
    char pad0[0x30];
    u8 unk30;
};

s32 func_002E6A80(struct func_002E6A80_arg0 *arg0) {
    return arg0->unk30 == 1;
}
