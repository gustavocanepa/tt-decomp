typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00773FC0[];
extern "C" void func_004B5A00(void *);
extern "C" void func_004B5A40(void *, s32) throw();

extern "C" void func_004B5FF0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004B5A00(D_00773FC0);
    if (prio == 0xFFFF && init == 0) func_004B5A40(D_00773FC0, 0x2);
}
