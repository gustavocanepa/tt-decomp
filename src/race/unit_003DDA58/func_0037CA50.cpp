#include "types.h"

struct Elem { char b[0x30]; };
struct Obj { char pad[0x30]; Elem *items; };
extern "C" s32 func_0037C740(Obj *, s32);

extern "C" Elem *func_0037CA50(Obj *o, s32 base, s32 x) {
    return &o->items[base + func_0037C740(o, x)];
}
