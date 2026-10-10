#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E5988(u32 arg0) {
    if (arg0 < 0x14U) {
        return *(s32 *)(0x5852A8 + (arg0 * 4));
    }
    return 0;
}
