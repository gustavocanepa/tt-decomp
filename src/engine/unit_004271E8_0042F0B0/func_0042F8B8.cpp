#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00586200[];
extern char D_006010F0[];
extern char D_005861F8[];
extern "C" void func_0042F440(void *, void *, void *);
extern "C" void func_0042F460(void *, s32) throw();

extern "C" void func_0042F8B8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0042F440(D_00586200, D_006010F0, D_005861F8);
    if (prio == 0xFFFF && init == 0) func_0042F460(D_00586200, 0x2);
}
