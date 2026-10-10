typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0076A058[];
extern char D_0076A088[];
extern char D_0076A090[];
extern "C" void func_004AE9C0(void *);
extern "C" void func_004A48C0(void *);
extern "C" void func_005357E8(void *);
extern "C" void func_004A48D8(void *, s32);
extern "C" void func_004AE9F0(void *, s32);

extern "C" void func_0042D670(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004AE9C0(D_0076A058);
    if (prio == 0xFFFF && init == 1) func_004A48C0(D_0076A088);
    if (prio == 0xFFFF && init == 1) func_005357E8(D_0076A090);
    if (prio == 0xFFFF && init == 0) func_004A48D8(D_0076A088, 0x2);
    if (prio == 0xFFFF && init == 0) func_004AE9F0(D_0076A058, 0x2);
}
