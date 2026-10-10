#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_003035F8(void);
extern s32 D_005865D0;
f32 func_00303628(void) {
    f32 f = func_003035F8();
    if (D_005865D0 == 1) {
        f *= 0.625f;
    }
    return f;
}
