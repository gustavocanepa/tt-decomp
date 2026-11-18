#include "types.h"

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct Elem { char data[0xB8]; };
struct Obj { struct VEntry *vtbl; struct Elem elems[2]; };

extern "C" s32 func_00403420(void *arg0, s32 arg1);

extern "C" void func_004036D0(struct Obj *o, s32 arg1)
{
    s32 v = arg1;
    int i;
    for (i = 0; i < 2; i++) v = func_00403420(&o->elems[i], v);
    struct VEntry *e = o->vtbl + 4;
    e->fn((char *)o + e->delta, arg1);
}
