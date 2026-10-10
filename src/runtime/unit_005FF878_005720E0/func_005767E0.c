#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004E5390();                            /* extern */

struct func_005767E0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

s32 func_005767E0(struct func_005767E0_arg0 *arg0) {
    if (arg0->unk1C == 0) {
        func_004E5390();
    }
}
