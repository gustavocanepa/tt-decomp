#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_005794E0[];
extern "C" void func_001055D0(void *) throw();

extern "C" void func_001055F8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_001055D0(D_005794E0);
}
