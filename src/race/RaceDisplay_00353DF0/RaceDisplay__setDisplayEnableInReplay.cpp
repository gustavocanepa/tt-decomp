#include "types.h"

struct VEntry_003A2008 {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj_003A2008 {
    VEntry_003A2008 *vtbl;
};

extern "C" void RaceDisplay__setDisplayEnableInReplay(struct Obj_003A2008 *arg0, s32 arg1) {
    VEntry_003A2008 *e = &arg0->vtbl[61];

    e->fn((char *)arg0 + e->delta, arg1 != 0);
}
