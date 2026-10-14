typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00578D28[];
extern s32 D_005DCFA4;
extern "C" void func_0047A6D8(void *, s32, void *, void *, s32, unsigned);
extern "C" void func_0047A1D0(void *, s32);

extern "C" void func_00100650(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0047A6D8(D_00578D28, D_005DCFA4, ((char *)"Q212GranTurismo413UpdateManager"), ((char *)"Q212GranTurismo413FileDevice"), 0, 0x7FFFFFFF);
    if (prio == 0xFFFF && init == 0) func_0047A1D0(D_00578D28, 2);
}
