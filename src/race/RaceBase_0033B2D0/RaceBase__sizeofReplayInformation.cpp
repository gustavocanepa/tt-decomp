#include "types.h"

struct VEntry_00389388 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_00389388 {
    char pad0[0x64];
    VEntry_00389388 *vtbl;
};

extern "C" s32 RaceBase__sizeofReplayInformation(struct Obj_00389388 *arg0) {
    VEntry_00389388 *e = &arg0->vtbl[66];

    return e->fn((char *)arg0 + e->delta) + 0x1A24;
}
