#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_002FEE80(s32, s32);
f32 func_003BCB48(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return -func_002FEE80(arg0, 0xA) * 0.39999998f;
    }
    return (-func_002FEE80(arg0, 0xA) * 180.0f) / 450.0f;
}
