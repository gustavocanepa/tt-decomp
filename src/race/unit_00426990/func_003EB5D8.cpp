typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_005853C0[];
extern "C" void RaceInput__structor_1(void *, s32);
extern "C" void RaceInput__structor_2(void *, s32) throw();

extern "C" void func_003EB5D8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) RaceInput__structor_1(D_005853C0, 0x0);
    if (prio == 0xFFFF && init == 0) RaceInput__structor_2(D_005853C0, 0x2);
}
