#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576A28_arg0 {
    char pad0[0x38];
    s32 unk38;
};

u32 func_00576A28(struct func_00576A28_arg0 *arg0) {
    return (u32) ~arg0->unk38 >> 0x1F;
}
