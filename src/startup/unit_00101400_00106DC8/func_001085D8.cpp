#include "types.h"
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00764068[];
extern char D_00579748[];
extern "C" void func_001081A8(void *, void *);
extern "C" void func_00108210(void *, s32);

extern "C" void func_001085D8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_001081A8(D_00764068, D_00579748);
    if (prio == 0xFFFF && init == 0) func_00108210(D_00764068, 0x2);
}
