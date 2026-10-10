typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00779680[];
extern char D_00779A80[];
extern "C" void func_004C9138(void *);
extern "C" void func_004C9138(void *);
extern "C" void func_004C9180(void *, s32) throw();
extern "C" void func_004C9180(void *, s32) throw();

extern "C" void func_004C97D8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004C9138(D_00779680);
    if (prio == 0xFFFF && init == 1) func_004C9138(D_00779A80);
    if (prio == 0xFFFF && init == 0) func_004C9180(D_00779A80, 0x2);
    if (prio == 0xFFFF && init == 0) func_004C9180(D_00779680, 0x2);
}
