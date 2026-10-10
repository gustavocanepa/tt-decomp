typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0057A938[];
extern "C" void func_001B1CB8(void *);
extern "C" void func_001B1D10(void *, s32) throw();

extern "C" void func_001B3350(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_001B1CB8(D_0057A938);
    if (prio == 0xFFFF && init == 0) func_001B1D10(D_0057A938, 0x2);
}
