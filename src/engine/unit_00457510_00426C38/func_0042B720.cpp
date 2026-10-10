typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00769D78[];
extern char D_00769DB8[];
extern "C" void func_0044C660(void *, void *, s32);
extern "C" void func_0044C6B8(void *, s32);

extern "C" void func_0042B720(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0044C660(D_00769D78, D_00769DB8, 0x20);
    if (prio == 0xFFFF && init == 0) func_0044C6B8(D_00769D78, 0x2);
}
