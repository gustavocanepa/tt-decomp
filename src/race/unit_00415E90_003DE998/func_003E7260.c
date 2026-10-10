#include "types.h"

s32 func_003E7230(s32 a, s32 b);

s32 func_003E7260(s32 n, s32 *values) {
    s32 r;
    s32 i;
    if (n <= 0) {
        return 0;
    }
    r = values[0];
    for (i = 1; i < n && r != 1; i++) {
        r = func_003E7230(r, values[i]);
    }
    return r;
}
