#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576340_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

s32 func_00576340(struct func_00576340_arg0 *arg0) {
    return arg0->unk1A & 4;
}
