typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00583F28[];
extern "C" void func_003402E0(void *);
extern "C" void func_003402F0(void *, s32) throw();

extern "C" void func_00340370(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_003402E0(D_00583F28);
    if (prio == 0xFFFF && init == 0) func_003402F0(D_00583F28, 0x2);
}
