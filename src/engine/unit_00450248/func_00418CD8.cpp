#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00585D10[];
extern char D_005FFE08[];
extern char D_00585D08[];
extern "C" void func_0042F440(void *, void *, void *);
extern "C" void func_0042F460(void *, s32);

extern "C" void func_00418CD8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0042F440(D_00585D10, D_005FFE08, D_00585D08);
    if (prio == 0xFFFF && init == 0) func_0042F460(D_00585D10, 0x2);
}
