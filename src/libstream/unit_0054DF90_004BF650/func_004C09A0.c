#include "types.h"

struct Pair { u16 lo; u16 hi; };
struct Rec { u32 idx; struct Pair val; };

void func_004C09A0(struct Pair *base, const struct Rec *r) {
    for (; r->idx; r++) {
        struct Pair *p = &base[r->idx];
        *p = r->val;
        if (p->hi == 0)
            p->hi = p->lo;
    }
}
