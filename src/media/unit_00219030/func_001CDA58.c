#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001CDA58_arg0 {
    char pad0[0x2C];
    s32 unk2C;
};

s32 func_001CDA58(struct func_001CDA58_arg0 *arg0) {
    return arg0->unk2C;
}
