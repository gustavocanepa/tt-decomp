#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001A2700_arg0 {
    char pad0[0x3D0];
    s32 unk3D0;
};

s32 func_001A2700(struct func_001A2700_arg0 *arg0) {
    return arg0->unk3D0;
}
