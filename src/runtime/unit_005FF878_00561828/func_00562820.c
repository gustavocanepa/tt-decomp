#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562820_arg0 {
    char pad0[0x10BC];
    s32 unk10BC;
};

s32 func_00562820(struct func_00562820_arg0 *arg0) {
    return arg0->unk10BC;
}
