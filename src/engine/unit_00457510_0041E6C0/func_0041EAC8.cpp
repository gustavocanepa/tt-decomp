#include "types.h"

struct V3 { f32 x, y, z; f32 pad; };
struct VEntry { s16 delta; s16 index; void (*fn)(V3 *, void *); };
struct Obj { VEntry *vtbl; };
extern "C" void func_004755EC(f32, f32, f32);

extern "C" void func_0041EAC8(Obj *o) {
    V3 v;
    VEntry *e = &o->vtbl[5];
    e->fn(&v, (char *)o + e->delta);
    func_004755EC(v.x, v.y, v.z);
}
