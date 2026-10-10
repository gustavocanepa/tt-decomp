#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E49C8_arg0 {
    char pad0[0x1CE8];
    s32 unk1CE8;
};

void *func_001E49C8(void *arg0) {
    return arg0 + (((struct func_001E49C8_arg0 *)arg0)->unk1CE8 * 0x38) + 0x718;
}
