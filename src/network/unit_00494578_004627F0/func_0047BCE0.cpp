typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0076FC80[];
extern "C" void func_0047A988(void *);
extern "C" void func_0047A920(void *, s32) throw();

extern "C" void func_0047BCE0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0047A988(D_0076FC80);
    if (prio == 0xFFFF && init == 0) func_0047A920(D_0076FC80, 0x2);
}
