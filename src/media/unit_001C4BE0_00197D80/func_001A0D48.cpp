#include "types.h"

extern char D_005E6C98[];
extern char D_005E6CB0[];

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x4C];
    char *sub;
};

extern "C" char *func_001A0D48(Obj *arg0) {
    char *res;
    VEntry *e = (VEntry *)(arg0->sub + 0x130);

    if (e->fn((char *)arg0 + e->delta) != 0) {
        res = D_005E6C98;
    } else {
        res = D_005E6CB0;
    }
    return res;
}
