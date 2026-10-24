#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00769968[];
extern "C" void func_004174C0(void *) throw();

extern "C" void func_004187B8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004174C0(D_00769968);
}
