#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8688_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x55C];
    u8 unk564;
};

s32 func_002F8688(struct func_002F8688_arg0 *arg0) {
    return arg0->unk4 + (arg0->unk564 * 0x10) + 0x208A0;
}
