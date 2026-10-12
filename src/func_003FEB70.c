#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005FA800[];
s32 func_003FEB70(s32 arg0) {
    if (arg0 < 0) {
        return (s32)D_005FA800;
    }
    return *(s32 *)(0x5856B0 + (arg0 * 4));
}
