typedef int s32;

struct Obj { char pad[0x34]; s32 m34; char pad2[8]; s32 m40; s32 m44; s32 m48; };
struct Guard { Obj *p; s32 pad[3]; };

extern "C" void *func_002B15D0(Guard *);
extern "C" void func_002B1578(Guard *, s32);

extern "C" void func_002B1800(void) {
    Guard g;
    Obj *p;
    func_002B15D0(&g);
    p = g.p;
    p->m34 = 2;
    p->m48 = p->m40;
    func_002B1578(&g, 2);
}
