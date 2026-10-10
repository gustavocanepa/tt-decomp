#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00434BC8(void);
s32 func_00434C28(void) {
    s32 v = func_00434BC8() * 8.0f;
    if (v >= 8) v = 7;
    return v;
}
