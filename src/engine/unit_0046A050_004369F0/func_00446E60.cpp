#include "types.h"
struct Ent00480100 {
    char p0[2];
    s16 lo;
    s16 hi;
    char p1[34];
};
struct List00480100 {
    struct Ent00480100 *base;
    s32 count;
};
struct Self00480100 {
    char p0[0x60];
    struct List00480100 *list;
    s32 thr;
    s32 p1;
    s32 idx;
};
extern "C" void func_00446F20(void *a, void *b, void *c, s32 d);

extern "C" void func_00446E60(struct Self00480100 *arg0, s32 arg1) {
    s32 loc[4];
    s32 idx;
    s32 count;
    struct Ent00480100 *e;
    s32 thr;
    s32 next;

    idx = arg0->idx;
    count = arg0->list->count;
    if (idx < count) {
        do {
            e = arg0->list->base + idx;
            thr = arg0->thr;
            if (thr < e->lo) {
                break;
            }
            if (thr < e->hi) {
                func_00446F20(loc, arg0, e, arg1);
            }
            next = arg0->idx + 1;
            arg0->idx = next;
            idx = next;
        } while (idx < count);
    }
}
