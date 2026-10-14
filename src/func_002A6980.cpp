extern char D_0057C250;
extern char D_005F12D0;
extern char D_002A6420;
extern char D_002A6448;
extern char D_002A6470;

typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern "C" void func_00297858(void *, void *, s32, void *, void *, void *);

extern "C" void func_002A6980(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00297858(&D_0057C250, &D_005F12D0, 0x1C, &D_002A6420, &D_002A6448, &D_002A6470);
}
