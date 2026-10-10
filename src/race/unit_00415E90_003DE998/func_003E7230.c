#include "types.h"

s32 func_003E7230(s32 a, s32 b) {
    if (b == 0) {
        return a;
    }
    return func_003E7230(b, a % b);
}
