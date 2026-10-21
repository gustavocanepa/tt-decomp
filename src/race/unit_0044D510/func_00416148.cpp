#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00585CC8[];
extern "C" void func_00415408(void *);
extern "C" void func_00415458(void *, s32) throw();

extern "C" void func_00416148(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00415408(D_00585CC8);
    if (prio == 0xFFFF && init == 0) func_00415458(D_00585CC8, 0x2);
}
