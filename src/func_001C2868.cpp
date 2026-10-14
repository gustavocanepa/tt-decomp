typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0057AB98[];
extern char D_005E8B90[];
extern char D_001C1930[];
extern char D_001C1958[];
extern "C" void func_001FC798(void *, void *, void *, void *);

extern "C" void func_001C2868(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_001FC798(D_0057AB98, D_005E8B90, D_001C1930, D_001C1958);
}
