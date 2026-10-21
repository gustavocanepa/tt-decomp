#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

extern Pair D_00585640[4];

extern "C" s32 func_003FD070(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_00585640[i].a == a && D_00585640[i].b == b) {
            return i;
        }
    }
    return 0;
}
