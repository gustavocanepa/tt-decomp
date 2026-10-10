#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576310_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

s32 func_00576310(struct func_00576310_arg0 *arg0) {
    return arg0->unk1A == 0;
}
