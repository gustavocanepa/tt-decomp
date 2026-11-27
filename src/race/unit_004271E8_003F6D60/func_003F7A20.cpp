#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00769550[];
extern char D_005F9BF0[];
extern "C" void func_004AC368(void *, void *, s32);

extern "C" void func_003F7A20(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004AC368(D_00769550, D_005F9BF0, 0x4);
}
