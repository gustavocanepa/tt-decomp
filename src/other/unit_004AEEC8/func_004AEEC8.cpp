typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_005981F0[];
extern "C" void func_004AEC60(void *);
extern "C" void func_004AECB8(void *, s32) throw();

extern "C" void func_004AEEC8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004AEC60(D_005981F0);
    if (prio == 0xFFFF && init == 0) func_004AECB8(D_005981F0, 0x2);
}
