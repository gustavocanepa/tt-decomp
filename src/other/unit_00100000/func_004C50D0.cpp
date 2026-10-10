typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0059C0E0[];
extern "C" void func_004C4D48(void *) throw();

extern "C" void func_004C50D0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004C4D48(D_0059C0E0);
}
