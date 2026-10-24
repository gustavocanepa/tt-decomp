#include "types.h"

struct Rec {
    s32 size;
    s32 a;
    s32 b;
};

extern "C" s32 func_0050B9D8(Rec *r) {
    s32 n = 0;
    while (r->size != 0) {
        if (r->a != 0 && r->b != 0)
            n++;
        r = (Rec *)((char *)r + r->size + 4);
    }
    return n;
}
