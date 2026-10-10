typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0059B718[];
extern "C" void func_004C3EF8(void *) throw();

extern "C" void func_004C41A8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004C3EF8(D_0059B718);
}
