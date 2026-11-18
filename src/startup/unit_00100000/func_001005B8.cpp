#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0061BBC8[];
extern "C" void func_00100250(void *);
extern "C" void func_00100290(void *, s32) throw();

extern "C" void func_001005B8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00100250(D_0061BBC8);
    if (prio == 0xFFFF && init == 0) func_00100290(D_0061BBC8, 0x2);
}
