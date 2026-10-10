typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00773E68[];
extern char D_00773E70[];
extern "C" void func_004A48C0(void *);
extern "C" void func_004B51E0(void *);
extern "C" void func_004B5210(void *, s32);
extern "C" void func_004A48D8(void *, s32);

extern "C" void func_004B5930(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004A48C0(D_00773E68);
    if (prio == 0xFFFF && init == 1) func_004B51E0(D_00773E70);
    if (prio == 0xFFFF && init == 0) func_004B5210(D_00773E70, 0x2);
    if (prio == 0xFFFF && init == 0) func_004A48D8(D_00773E68, 0x2);
}
