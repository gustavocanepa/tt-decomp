typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00598C40[];
extern "C" void func_004C1F28(void *);
extern "C" void func_004C1F58(void *, s32) throw();

extern "C" void func_004C2000(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004C1F28(D_00598C40);
    if (prio == 0xFFFF && init == 0) func_004C1F58(D_00598C40, 0x2);
}
