#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002668E8(s32);                             /* extern */

struct func_001E55C0_arg0 {
    char pad0[0x1D50];
    s32 unk1D50;
};

s32 func_001E55C0(struct func_001E55C0_arg0 *arg0) {
    return func_002668E8(arg0->unk1D50) == (s32) arg0;
}
