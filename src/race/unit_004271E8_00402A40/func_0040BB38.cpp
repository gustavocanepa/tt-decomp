#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00585A30[];
extern "C" void func_0040AD60(void *);
extern "C" void func_0040ADD0(void *, s32) throw();

extern "C" void func_0040BB38(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0040AD60(D_00585A30);
    if (prio == 0xFFFF && init == 0) func_0040ADD0(D_00585A30, 0x2);
}
