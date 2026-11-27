/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Stores a pair of 32-bit values from arg1 as two 16-bit fields at +0x64/+0x66 and marks the
   object dirty (+0x1F), like the neighbouring setters of this unit. */
#include "types.h"

struct Pair {
    s32 x;
    s32 y;
};

struct Obj {
    char pad0[0x1F];
    u8 dirty;
    char pad20[0x44];
    s16 x;
    s16 y;
};

void func_004C79E8(struct Obj *obj, const struct Pair *p)
{
    s32 x = p->x;
    s32 y = p->y;
    obj->x = x;
    obj->y = y;
    obj->dirty = 1;
}
