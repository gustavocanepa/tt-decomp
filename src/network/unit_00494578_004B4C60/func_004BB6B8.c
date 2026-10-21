#include "types.h"
typedef struct { s32 (*f)(s32 a, s32 b); s32 a; } Hook;
extern Hook D_005983F0;
s32 func_004BB6B8(void) {
    return D_005983F0.f(D_005983F0.a, 0);
}
