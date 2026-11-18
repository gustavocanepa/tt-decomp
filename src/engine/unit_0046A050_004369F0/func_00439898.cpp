#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_005865D0[];
extern "C" void func_00438EE8(void *);
extern "C" void func_00438F18(void *, s32) throw();

extern "C" void func_00439898(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00438EE8(D_005865D0);
    if (prio == 0xFFFF && init == 0) func_00438F18(D_005865D0, 0x2);
}
