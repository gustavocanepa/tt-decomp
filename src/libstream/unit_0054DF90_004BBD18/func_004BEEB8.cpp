#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00776D80[];
extern "C" void func_004BE890(void *);
extern "C" void func_004BE8D0(void *, s32) throw();

extern "C" void func_004BEEB8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004BE890(D_00776D80);
    if (prio == 0xFFFF && init == 0) func_004BE8D0(D_00776D80, 0x2);
}
