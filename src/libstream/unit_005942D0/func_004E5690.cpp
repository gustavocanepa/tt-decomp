typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern "C" void func_004E65C8(void);

extern "C" void func_004E5690(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 0) func_004E65C8();
}
