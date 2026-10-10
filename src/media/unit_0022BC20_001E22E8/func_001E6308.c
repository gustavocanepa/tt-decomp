#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E6308_arg0 {
    char pad0[0x1D54];
    s32 unk1D54;
};

s32 func_001E6308(struct func_001E6308_arg0 *arg0) {
    return arg0->unk1D54;
}
