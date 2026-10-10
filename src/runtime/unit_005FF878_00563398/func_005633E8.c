#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005633E8_arg0 {
    char pad0[0x8];
    u8 unk8;
};

s32 func_005633E8(struct func_005633E8_arg0 *arg0) {
    return arg0->unk8 != 0;
}
