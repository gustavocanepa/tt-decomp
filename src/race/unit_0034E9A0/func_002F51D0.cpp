#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00582E98[];
extern "C" void func_002F4E48(void *) throw();

extern "C" void func_002F51D0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_002F4E48(D_00582E98);
}
