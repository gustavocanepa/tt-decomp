#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

extern Pair D_005983E0[5];

extern "C" void func_004BB5D0(s32 arg0) {
    s32 i;
    Pair *p = D_005983E0;
    for (i = 0; i < 5; i++, p++) {
        if (arg0 == p->a) {
            p->b = 0;
            p->a = 0;
            return;
        }
    }
}
