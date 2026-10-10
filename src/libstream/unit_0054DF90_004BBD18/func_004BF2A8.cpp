typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00776E40[];
extern "C" void func_004BEF50(void *);
extern "C" void func_004BEF90(void *, s32) throw();

extern "C" void func_004BF2A8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004BEF50(D_00776E40);
    if (prio == 0xFFFF && init == 0) func_004BEF90(D_00776E40, 0x2);
}
