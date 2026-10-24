#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00583690[];
extern "C" void func_0030E430(void *) throw();

extern "C" void func_0030E688(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0030E430(D_00583690);
}
