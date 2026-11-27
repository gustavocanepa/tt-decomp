#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00774100[];
extern char D_00774200[];
extern "C" void func_004B6088(void *);
extern "C" void func_004B6178(void *);
extern "C" void func_004B61B8(void *, s32) throw();
extern "C" void func_004B60E0(void *, s32) throw();

extern "C" void func_004B6690(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004B6088(D_00774100);
    if (prio == 0xFFFF && init == 1) func_004B6178(D_00774200);
    if (prio == 0xFFFF && init == 0) func_004B61B8(D_00774200, 0x2);
    if (prio == 0xFFFF && init == 0) func_004B60E0(D_00774100, 0x2);
}
