#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern f32 D_006052E4;
f32 func_00475670(f32 fparg0) {
    if (fparg0 == 0.0f) return D_006052E4;
    return 1.0f / fparg0;
}
