#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_002F9A78(void);
extern f32 D_007673B8;
extern f32 D_007673BC;
f32 func_002F9E60(void) {
    f32 x = func_002F9A78();
    if (D_007673BC <= x) return 1.0f;
    if (x <= D_007673B8) return 0.0f;
    return (x - D_007673B8) / (D_007673BC - D_007673B8);
}
