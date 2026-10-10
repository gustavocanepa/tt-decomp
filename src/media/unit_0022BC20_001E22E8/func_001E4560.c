#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FC448(s32);
s32 func_001E4560(s8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0x6D8);
    s32 temp_v0;
    temp_v0 = *p;
    if ((temp_v0 != 0) && (func_001FC448(temp_v0) != 0)) {
        return *p;
    }
    return 0;
}
