#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00586A68[];
extern "C" void func_004559D8(void *);
extern "C" void func_004559F8(void *, s32) throw();

extern "C" void func_00455A88(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004559D8(D_00586A68);
    if (prio == 0xFFFF && init == 0) func_004559F8(D_00586A68, 0x2);
}
