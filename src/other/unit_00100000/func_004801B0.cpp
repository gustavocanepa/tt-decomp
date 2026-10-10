typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0058C5B0[];
extern char D_0058E060[];
extern "C" void func_0047FB70(void *);
extern "C" void func_004AE9C0(void *);
extern "C" void func_004AE9F0(void *, s32) throw();
extern "C" void func_0047FC08(void *, s32) throw();

extern "C" void func_004801B0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0047FB70(D_0058C5B0);
    if (prio == 0xFFFF && init == 1) func_004AE9C0(D_0058E060);
    if (prio == 0xFFFF && init == 0) func_004AE9F0(D_0058E060, 0x2);
    if (prio == 0xFFFF && init == 0) func_0047FC08(D_0058C5B0, 0x2);
}
