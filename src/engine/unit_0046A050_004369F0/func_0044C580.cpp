#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00586990[];
extern char D_0076BE70[];
extern "C" void func_0044C660(void *, void *, s32);
extern "C" void func_0044C6B8(void *, s32);

extern "C" void func_0044C580(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0044C660(D_00586990, D_0076BE70, 0x100);
    if (prio == 0xFFFF && init == 0) func_0044C6B8(D_00586990, 0x2);
}
