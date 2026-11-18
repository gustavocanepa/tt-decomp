#include "types.h"
struct VEnt { short adj; short pad; void (*fn)(void *); };
struct Vt { char pad[0x2D0]; VEnt e; };
struct Sub { s32 f0; char pad[0xDC - 4]; s32 fDC; };
struct Self {
    char pad[0x64]; Vt *vt; char pad1[4]; s32 sub;
    char pad2[0xE0C - 0x70]; s32 fD48;
};
#define SUB(a) ((Sub *)(a)->sub)
extern char D_005DEE30[];
extern "C" void func_0010B458(void *);
extern "C" void func_0011FAD0(int);
extern "C" void func_0011FAE0(int);
extern "C" void func_0033A158(void *, int, int);

extern "C" void func_0010CF58(Self *arg0) {
    s32 one = 1;
    Sub *s = SUB(arg0);
    s->fDC = one;
    s32 saved = s->f0;
    SUB(arg0)->f0 = 0;
    arg0->fD48 = one;
    func_0033A158(arg0, 4, 1);
    func_0011FAD0((int)arg0);
    func_0011FAE0(1);
    func_0010B458(D_005DEE30);
    func_0011FAD0(0);
    VEnt *e = &arg0->vt->e;
    e->fn((char *)arg0 + e->adj);
    arg0->fD48 = 0;
    SUB(arg0)->fDC = 0;
    SUB(arg0)->f0 = saved;
}
