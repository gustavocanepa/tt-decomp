#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_005845D0[];
extern "C" void func_00376FE8(void *) throw();

extern "C" void func_00377290(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00376FE8(D_005845D0);
}
