#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_001FFCD0_arg0 {
    char pad0[0xDC];
    s16 unkDC;
};

s32 func_001FFCD0(void *arg0, s32 arg1) {
    return (s32) M2C_FIELD(((arg1 * 2) + arg0), u16 *, 0xC4) >= ((struct func_001FFCD0_arg0 *)arg0)->unkDC;
}
