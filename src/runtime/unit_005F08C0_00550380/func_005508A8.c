#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005508A8_arg0 {
    char pad0[0x2B0];
    s32 unk2B0;
};

u32 func_005508A8(struct func_005508A8_arg0 *arg0) {
    return (u32) ~arg0->unk2B0 >> 0x1F;
}
