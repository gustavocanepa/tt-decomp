#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001A2748_arg0 {
    char pad0[0x3D0];
    s32 unk3D0;
};

s32 func_001A2748(struct func_001A2748_arg0 *arg0) {
    arg0->unk3D0 = 0;
    return 0;
}
